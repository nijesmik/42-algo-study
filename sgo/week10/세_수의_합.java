
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{

		Scanner sc = new Scanner(System.in);
		int N, num[], sum[], count = 0;

		N = sc.nextInt();
		num = new int[N];
		sum = new int[N * N];

		for (int i = 0; i < N; i++) {
			num[i] = sc.nextInt();
		}
		Arrays.sort(num);

		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				sum[count++] = num[i] + num[j];
			}
		}
		Arrays.sort(sum, 0, count - 1);

		for (int i = N - 1; 0 <= i; i--) {
			for (int j = i; 0 <= j; j--) {
				if (Arrays.binarySearch(sum, 0, count - 1, num[i] - num[j]) < 0) continue;
				System.out.println(num[i]);
				return;
			}
		}
	}
}
