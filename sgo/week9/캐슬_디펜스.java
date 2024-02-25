
import java.io.*;
import java.lang.reflect.Parameter;
import java.nio.file.attribute.PosixFileAttributes;
import java.util.*;

import javax.lang.model.type.ArrayType;

public class Main {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int N, M, D, max;
	static int[][] map, tmpMap;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		tmpMap = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		copyMap(map, tmpMap);
		ArrayList<Pair> lst = new ArrayList<>();
		boolean[] visitied = new boolean[M];
		max = 0;
		combination(lst, visitied, 0, 3);
		System.out.println(max);

	}

	static int calLen (int ax, int ay, int bx, int by) {
		return Math.abs(ax - bx) + Math.abs(ay - by);
	}

	static int[][] moveEnemy () {
		int[][] tmp = new int[N][M];
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = map[i - 1][j];
			}
		}
		return tmp;
	}

	static void copyMap(int[][] origin, int[][] copy) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy[i][j] = origin[i][j];
			}
		}
	}

	static void combination(ArrayList<Pair> lst, boolean[] visited, int start, int r) {
		if(r == 0) {
			int kill = 0;
			for (int i = 0; i < N; i++) {
				boolean[] isAttack = new boolean[3];
				ArrayList<Pair> killLst = new ArrayList<>();
				for (int d = 1; d <= D; d++) {
					for  (int k = 0; k < M; k++){
						for (int j = 0; j < N; j++) {
							boolean isKill = false;
							for (int l = 0; l < 3; l++) {
								if ((map[j][k] == 1 || map[j][k] == -1) && !isAttack[l] && calLen(k, j, lst.get(l).x, lst.get(l).y) == d) {
									if (map[j][k] == 1) {
										isKill = true;
										killLst.add(new Pair(k, j));
										map[j][k] = -1;
									}
									isAttack[l] = true;
								}
							}
							if (isKill){
								kill++;
							}
						}
					}
				}
				for(Pair killPair : killLst) {
					map[killPair.y][killPair.x] = 0;
				}
				map = moveEnemy();
			}
			max = Math.max(max, kill);
			copyMap(tmpMap, map);
			return;
		}

		for(int i=start; i < M; i++) {
			visited[i] = true;
			lst.add(new Pair(i, N));
			combination(lst, visited, i + 1, r - 1);
			visited[i] = false;
			lst.remove(3 - r);
		}
	}
}

class Pair {
	int x;
	int y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "Pair{" +
			"x=" + x +
			", y=" + y +
			'}';
	}
}
