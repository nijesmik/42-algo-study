
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

		char[][] map = new char[N][M];
		boolean[][] visitied = new boolean[N][M];
		Pair playerXY = new Pair(0,0,0);
		Queue<Pair> fireQue = new LinkedList<>();
		visitied[playerXY.y][playerXY.x] = true;
		for (int i = 0; i < N; i++) {
			String line = br.readLine();
			for (int j = 0; j < M; j++) {
				char a = line.charAt(j);
				map[i][j] = a;
				if (a == 'J')
					playerXY = new Pair(j, i, 0);
				if (a == 'F')
					fireQue.add(new Pair(j, i, 0));
				if (a == 'F' || a == 'J' || a == '#')
					visitied[i][j] = true;
			}
		}
		Queue<Pair> queue = new LinkedList<>();
		queue.add(playerXY);
		int outLen = 0;
		while (!queue.isEmpty()) {
			Pair pair = queue.poll();
			while (!fireQue.isEmpty() && fireQue.peek().d == pair.d) {
				Pair fire = fireQue.poll();
				for (int i = 0; i < 4; i++) {
					int nx = fire.x + dx[i];
					int ny = fire.y + dy[i];
					if ((nx >= 0 && ny >= 0 & nx < M && ny < N) && map[ny][nx] != 'F' && !visitied[ny][nx]) {
						fireQue.add(new Pair(nx, ny, fire.d + 1));
						map[ny][nx] = 'F';
					}
				}
			}
			
			for (int i = 0; i < 4; i++) {
				int nx = pair.x + dx[i];
				int ny = pair.y + dy[i];
				boolean isIn = nx >= 0 && ny >= 0 && nx < M && ny < N;
				if (isIn && map[ny][nx] != 'F' && !visitied[ny][nx]){
					visitied[ny][nx] = true;
					queue.add(new Pair(nx, ny, pair.d + 1));
				} else if (!isIn){
					outLen = pair.d + 1;
				}
			}
			if (outLen != 0)
				break;
		}
		if (outLen == 0) {
			System.out.println("IMPOSSIBLE");
		} else{
			System.out.println(outLen);
		}
	}
}

class Pair {
	int x;
	int y;
	int d;

	public Pair(int x, int y, int d) {
		this.x = x;
		this.y = y;
		this.d = d;
	}

	@Override
	public String toString() {
		return "Pair{" +
			"x=" + x +
			", y=" + y +
			", d=" + d +
			'}';
	}
}
