
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int flowerCnt = Integer.parseInt(br.readLine().trim());
		Flower[] flowers = new Flower[flowerCnt];
		StringTokenizer st;
		for (int i = 0; i < flowerCnt; i++) {
			st = new StringTokenizer(br.readLine().trim(), " ");
			int startMonth = Integer.parseInt(st.nextToken());
			int startDay = Integer.parseInt(st.nextToken());
			int endMonth = Integer.parseInt(st.nextToken());
			int endDay = Integer.parseInt(st.nextToken());
			flowers[i] = new Flower(startMonth * 100 + startDay, endMonth * 100 + endDay);
		}

		Arrays.sort(flowers);

		int startDay = 301;
		int endDay = 1201;
		int count = 0;
		int max = 0;
		int startIdx = 0;
		boolean isFind = false;

		while (startDay < endDay) {
			isFind = false;
			for (int i = startIdx; i < flowerCnt; i++) {
				if (flowers[i].start > startDay) {
					break;
				}
				if (max < flowers[i].end) {
					max = flowers[i].end;
					startIdx = i + 1;
					isFind = true;
				}
			}
			if (isFind) {
				startDay = max;
				count += 1;
			} else {
				break;
			}
		}
		if (max < endDay) {
			System.out.println(0);
		} else {
			System.out.println(count);
		}

	}

	static class Flower implements Comparable<Flower> {
		int start;
		int end;

		public Flower(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Flower f) {
			if (this.start != f.start) {
				return this.start - f.start;
			} else {
				return -this.end + f.end;
			}
		}
	}
}
