
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[N];
		int max = 0;
		int maxIndex = 0;
		boolean desc = false; // 내림차순
		boolean asc = false; // 오름차순
		boolean haveDesc = false;
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				if (desc) {
					max = arr[i - 1];
					maxIndex = i - 1;
				}
				asc = true;
				desc = false;
			} else {
				haveDesc = true;
				asc = false;
				desc = true;
			}
		}
		if (desc) {
			int tmp = arr[N - 1];
			arr[N - 1] = arr[N - 2];
			arr[N - 2] = tmp;
		} else {
			int second = 0;
			int secondIndex = 0;
			for (int i = maxIndex + 1; i < N; i++) {
				if (arr[i] < max) {
					second = Math.max(second, arr[i]);
					secondIndex = i;
				}
			}
			int tmp = arr[maxIndex];
			arr[maxIndex] = arr[secondIndex];
			arr[secondIndex] = tmp;

			for (int i = maxIndex + 1; i < N - 1; i++) {
				for (int j = maxIndex + 1; j < N - 1; j++) {
					if (arr[j] <  arr[j + 1]) {
						tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		if (!haveDesc) {
			sb.append("-1");
		} else {
			for (int i = 0; i < N; i++) {
				sb.append(arr[i]).append(" ");
			}
		}
		System.out.println(sb);
	}
}
