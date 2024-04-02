
import java.io.*;
import java.util.*;

public class Main {
	static int N,M, max;
	static int[][] map;
	static int[][] visited;
	static int[] dx = {1, 0};
	static int[] dy = {0, 1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		visited = new int[N][M];
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = Character.getNumericValue(input.charAt(j));
			}
		}
		max = map[0][0];
		dfs(0, 0, 0);
		System.out.println(max);
	}

	static void dfs(int x, int y, int sum) {
		int ny, nx;
		int xx = x + 1;
		int yy = y;
		if (xx >= M) {
			xx = 0;
			yy++;
			if (yy >= N) {
				max = Math.max(sum, max);
				return;
			}
		}
		if (visited[y][x] == 1){
			dfs(xx, yy, sum);
			return ;
		}else {
			visited[y][x] = 1;
		}
		int origin = map[y][x];
		for (int k = 0; k < 2; k++) { // 2 가지 방향
			for (int i = 0; i < 4; i++) { // 4번의
				ny = y;
				nx = x;
				int lineSum = origin;
				int index = i;
				for (int j = 0; j <= i; j++) {
					ny = ny + dy[k];
					nx = nx + dx[k];
					if (ny >= 0 && nx >= 0 && ny < N && nx < M && visited[ny][nx] == 0) {
						visited[ny][nx] = 1;
						lineSum = lineSum * 10 + map[ny][nx];
					} else {
						index = j - 1;
						break;
					}
				}
				if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
					dfs(xx, yy, sum + lineSum);
				}
				ny = y;
				nx = x;
				for (int j = 0; j <= index; j++) {
					ny = ny + dy[k];
					nx = nx + dx[k];
					if (ny >= 0 && nx >= 0 && ny < N && nx < M && visited[ny][nx] == 1) {
						visited[ny][nx] = 0;
					}
				}
			}
		}
		visited[y][x] = 0;
	}
}
