
import java.io.*;
import java.util.*;

public class Main {
	static int[][] map = new int[101][101];
	static int[][] visited = new int[101][101];
	static int[] dx = {1,-1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int lev = 0;
		int nx, ny;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0){
					Queue<Pair> q = new LinkedList<>();
					q.add(new Pair(j, i, 0));
					map[i][j] = lev + 1;
					visited[i][j] = 1;
					while (!q.isEmpty()) {
						Pair pair = q.poll();
						for (int k = 0; k < 4; k++) {
							nx = pair.x + dx[k];
							ny = pair.y + dy[k];
							if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[ny][nx] == 1 && visited[ny][nx] == 0) {
								map[ny][nx] = lev + 1;
								visited[ny][nx] = 1;
								q.add(new Pair(nx, ny, 0 ));
							}
						}
					}
					lev++;
				}
			}
		}
		int min = 10000000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0)
					continue;
				visited = new int[101][101];
				PriorityQueue<Pair> q = new PriorityQueue<>();
				q.add(new Pair(j, i, 0));
				int origin = map[i][j];
				visited[i][j] = 0;
				while (!q.isEmpty()) {
					Pair pair = q.poll();
					for (int k = 0; k < 4; k++) {
						nx = pair.x + dx[k];
						ny = pair.y + dy[k];
						if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[ny][nx] != origin && visited[ny][nx] == 0 && map[ny][nx] != 0) {
							min = Math.min(min, pair.len);
							continue;
						}
						if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[ny][nx] == 0 && visited[ny][nx] == 0) {
							visited[ny][nx] = 1;
							q.add(new Pair(nx, ny, pair.len + 1));
						}
					}
				}
			}
		}
		System.out.println(min);

	}

}

class Pair implements Comparable<Pair>{
	int x;
	int y;
	int len;

	public Pair(int x, int y, int len) {
		this.x = x;
		this.y = y;
		this.len = len;
	}

	@Override
	public int compareTo(Pair o) {
		return this.len - o.len;
	}
}
