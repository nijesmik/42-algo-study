
import java.io.*;
import java.lang.reflect.Parameter;
import java.nio.file.attribute.PosixFileAttributes;
import java.util.*;

import javax.lang.model.type.ArrayType;

public class Main {
	static Pair right = new Pair(1, 0);
	static Pair left = new Pair(-1, 0);
	static Pair up = new Pair(0, -1);
	static Pair down = new Pair(0, 1);
	static Pair[] i1 = {right, right, right};
	static Pair[] i2 = {down, down, down};
	static Pair[] o1 = {right, down, left};
	static Pair[] l1 = {right, down, down};
	static Pair[] l2 = {left, down, down};
	static Pair[] l3 = {right, right, up};
	static Pair[] l4 = {right, right, down};
	static Pair[] l5 = {down, down, right};
	static Pair[] l6 = {down, down, left};
	static Pair[] l7 = {left, left, down};
	static Pair[] l8 = {left, left, up};
	static Pair[] z1 = {right, down, right};
	static Pair[] z2 = {down, right, down};
	static Pair[] z3 = {up, right, up};
	static Pair[] z4 = {right, up, right};
	static Pair[] t1 = {right, up, new Pair(0, 2)};
	static Pair[] t2 = {down, left, new Pair(2,0)};
	static Pair[] t3 = {down, down, new Pair(1, -1)};
	static Pair[] t4 = {right, right, new Pair(-1, 1)};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ArrayList<Pair[]> lst = new ArrayList<>();
		lst.add(i1); lst.add(i2);
		lst.add(o1);
		lst.add(l1); lst.add(l2); lst.add(l3); lst.add(l4);
		lst.add(l5); lst.add(l6); lst.add(l7); lst.add(l8);
		lst.add(z1); lst.add(z2); lst.add(z3); lst.add(z4);
		lst.add(t1); lst.add(t2); lst.add(t3); lst.add(t4);
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int cnt;
				for (Pair[] block: lst) {
					int x = j; int y = i;
					cnt = map[i][j];
					for (int k = 0; k < 3; k++) {
						int nx = block[k].x + x;
						int ny = block[k].y + y;
						if (nx >= 0 && nx < M && ny >=0 && ny < N) {
							cnt += map[ny][nx];
						}
						x = nx;
						y = ny;
					}
					max = Math.max(max, cnt);
				}
			}
		}
		System.out.println(max);
	}
}

class Pair {
	int x;
	int y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
