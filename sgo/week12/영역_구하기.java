
import java.io.*;
import java.util.*;

public class Main {
	static int[][] map;
	static int M, N, size;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		map = new int[101][101];
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			paintMap(x1, y1, x2, y2);
		}
		StringBuilder sb = new StringBuilder();
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0){
					size = 0;
					cnt++;
					map[i][j] = 1;
					dfs(j, i);
					pq.add(size);
				}
			}
		}
		System.out.println(cnt);
		while (!pq.isEmpty()) {
			sb.append(pq.poll()).append(" ");
		}
		System.out.println(sb);
	}

	static void paintMap(int x1, int y1, int x2, int y2) {
		for (int i = M - y2; i < M - y1; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = 1;
			}
		}
	}

	static void dfs(int x, int y) {
		size++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[ny][nx] == 0) {
				map[ny][nx] = 1;
				dfs(nx, ny);
			}
		}
	}
}
