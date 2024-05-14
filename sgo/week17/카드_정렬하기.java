
import java.io.*;
import java.util.*;

public class Main {
	static int N, M, res;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		for (int i = 0; i < N; i++) {
			pq.add(Integer.parseInt(br.readLine()));
		}
		int sum = 0;
		if (pq.size() > 1)  {
			while (pq.size() > 1) {
				int a = pq.poll();
				int b = pq.poll();
				int plus = a + b;
				sum += plus;
				pq.add(plus);
			}
		}
		System.out.println(sum);
	}
}

