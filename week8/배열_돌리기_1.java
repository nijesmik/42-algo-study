
import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int t = 0; t < R; t++) {
			map = rotate(M, N, map);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(map[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	static int[][] rotate (int M, int N, int[][] map) {
		int x, y, nx, ny;
		int[][] res = new int[N][M];
		int cy = N;
		int cx = M;
		for (int i = 0; i < Math.min(N, M) / 2; i++) {
			int dir = 0;
			x = M - cx;
			y = N - cy;
			while (true) {
				nx = x + dx[dir];
				ny = y + dy[dir];
				if (nx < N - cy || ny < N - cy || nx >= cx || ny >= cy) {
					dir++;
					if (dir >= 4)
						break;
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
				res[y][x] = map[ny][nx];
				y = ny; x = nx;
			}
			cx--;
			cy--;
		}
		return res;
	}
}
