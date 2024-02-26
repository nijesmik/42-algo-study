
import java.io.*;
import java.util.*;

public class Main {

	static boolean[] button;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		button = new boolean[10];
		Arrays.fill(button, true);
		if (M != 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < M; i++) {
				int input = Integer.parseInt(st.nextToken());
				button[input] = false;
			}
		}
		int min = 1000000;
		for (int i = 0; i < 1000000; i++) {
			int digit = cal(i);
			if (digit != -1){
				min = Math.min(min, digit + Math.abs(N - i));
			}
		}
		min = Math.min(min, Math.abs(100 - N));
		System.out.println(min);
	}

	static int cal(int n) {
		if (n == 0) {
			if (!button[0])
				return -1;
			return 1;
		}
		int cnt = 0;
		while (n > 0) {
			int check = n % 10;
			if (!button[check])
				return (-1);
			n /= 10;
			cnt++;
		}
		return cnt;
	}
}
