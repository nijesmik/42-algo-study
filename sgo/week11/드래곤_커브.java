
import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, -1, 0, 1};
	// 3 -> 0
	// 0 -> 1
	// 1 -> 2
	// 2 -> 3
	static int[] dir = {1, 2, 3, 0};
	public static void main(String[] args) throws Exception{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		boolean[][] visited = new boolean[101][101];
		int x, y, d, g, nx, ny;
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			visited[y][x] = true;
			ArrayList<Integer> dirLst = new ArrayList<>();
			dirLst.add(d);
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx >=0 && ny >= 0 && nx <= 100 && ny <= 100) {
				visited[ny][nx] = true;
			}
			x = nx; y = ny;
			for (int j = 1; j <= g; j++) { // 세대 만큼 반복
				Stack<Integer> stack = new Stack<>();
				for (int k = 0; k < dirLst.size(); k++) { // 세대 별로 이동 방향을 스택에 저장
					d = dir[dirLst.get(k)];
					stack.push(d);
				}
				while (!stack.isEmpty()) {
					d = stack.pop();
					dirLst.add(d);
					nx = x + dx[d];
					ny = y + dy[d];
					if (nx >=0 && ny >= 0 && nx <= 100 && ny <= 100) {
						visited[ny][nx] = true;
					}
					x = nx; y = ny;
				}
			}
		}
		System.out.println(cntSquare(visited));
	}
	static int cntSquare(boolean[][] visited) {
		int cnt = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
					cnt++;
			}
		}
		return cnt;
	}
}
