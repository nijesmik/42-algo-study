import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		for (int i = 0; i < N; i++) {
			pq.add(Integer.parseInt(br.readLine()));
		}
		int i = 1;
		int max = 0;
		while (!pq.isEmpty()) {
			int now = pq.poll();
			max = Math.max(max, now * i);
			i++;
		}
		System.out.println(max);
	}
}
