
import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {-1, 0, 1, 0};
	static int R,C,T;
	static int[][] map;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		int upCleaner = -1;
		int downCleaner = -1;
		map = new int[R][C];
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				int input = Integer.parseInt(st.nextToken());
				map[i][j] = input;
				if (input == -1) {
					if (upCleaner == -1)
						upCleaner = i;
					else 
						downCleaner = i;
				}
			}
		}
		for (int i = 0; i < T; i++) {
			map = spreadDust(map);
			turnMapUp(upCleaner);
			turnMapDown(downCleaner);
		}
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != -1)
					cnt += map[i][j];
			}
		}
		System.out.println(cnt);
	}

	public static int[][] spreadDust(int[][] map) {
		int[][] tmp = new int[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int dustOrigin = map[i][j];
				int spreadDust = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] != -1) {
						tmp[ny][nx] += spreadDust;
						dustOrigin -= spreadDust;
					}
				}
				tmp[i][j] += dustOrigin;
			}
		}
		return tmp;
	}

	static void turnMapUp(int upCleaner) {
		int dir = 0;
		int x = 0;
		int y = upCleaner - 1;
		while (x != 0 || y != upCleaner) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= C || ny > upCleaner) {
				dir++;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
			if (map[ny][nx] == -1)
				map[y][x] = 0;
			else
				map[y][x] = map[ny][nx];
			x = nx;
			y = ny;
		}
	}
	static void turnMapDown(int downCleaner) {
		int dir = 0;
		int x = 0;
		int y = downCleaner + 1;
		while (x != 0 || y != downCleaner) {
			int nx = x + dx[dir];
			int ny = y + dy[dir] * -1;
			if (nx < 0 || ny >= R || nx >= C || ny < downCleaner) {
				dir++;
				nx = x + dx[dir];
				ny = y + dy[dir] * -1;
			}
			if (map[ny][nx] == -1)
				map[y][x] = 0;
			else
				map[y][x] = map[ny][nx];
			x = nx;
			y = ny;
		}
	}
}
