
import java.io.*;
import java.lang.reflect.Parameter;
import java.nio.file.attribute.PosixFileAttributes;
import java.util.*;

import javax.lang.model.type.ArrayType;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int NA = Integer.parseInt(st.nextToken());
		int NB = Integer.parseInt(st.nextToken());

		HashMap<Integer, Integer> map = new HashMap<>();
		PriorityQueue<Integer> pq = new PriorityQueue();
		int now;
		st = new StringTokenizer(br.readLine());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for (int i = 0; i < NB; i++) {
			now = Integer.parseInt(st2.nextToken());
			map.put(now, 1);
		}
		int cnt = 0;
		for (int i = 0; i < NA; i++) {
			now = Integer.parseInt(st.nextToken());
			if (!map.containsKey(now)) {
				cnt++;
				pq.add(now);
			}
		}

		StringBuilder sb = new StringBuilder();
		System.out.println(cnt);
		while (!pq.isEmpty()) {
			sb.append(pq.poll()).append(" ");
		}
		System.out.println(sb);
	}
}
