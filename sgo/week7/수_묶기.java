
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		PriorityQueue<Integer> pqP = new PriorityQueue<>(Collections.reverseOrder());
		PriorityQueue<Integer> pqM = new PriorityQueue<>();
		for (int i = 0; i < N; i++) {
			int input = sc.nextInt();
			if (input > 0)
				pqP.add(input);
			else
				pqM.add(input);
		}
		int cnt = 0;
		while (!pqP.isEmpty()) {
			int now = pqP.poll();
			if (!pqP.isEmpty()) {
				int next = pqP.peek();
				if (now * next > now + next) {
					cnt += now * next;
					pqP.poll();
				} else {
					cnt += now;
				}
			} else {
				cnt += now;
			}
		}
		while (!pqM.isEmpty()) {
			int now = pqM.poll();
			if (!pqM.isEmpty()) {
				int next = pqM.poll();
				cnt += now * next;
			} else {
				cnt += now;
			}
		}
		System.out.println(cnt);
	}
}
