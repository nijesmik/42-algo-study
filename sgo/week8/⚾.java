
import java.io.*;
import java.util.*;

public class Main {

	static int N, res;
	static int[][] arr;
 	static int[] batting_order;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[50][9];
		batting_order = new int[9];
		batting_order[3] = 0;
		boolean[] visited = new boolean[9];
		visited[0] = true;
		res = 0;
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 9; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0, visited);
		System.out.println(res);
	}

	static void dfs(int d, boolean[] visited) {
		if (d == 9){
			get_score();
		}
		if (d == 3) {
			dfs(d + 1, visited);
			return;
		}
		for (int i = 0; i < 9; i++) {
			if (!visited[i]) {
				visited[i] = true;
				batting_order[d] = i;
				dfs(d + 1, visited);
				visited[i] = false;
			}
		}
	}

	static void get_score() {
		int index = 0;
		int score = 0;
		for (int i = 0; i < N; i++) {
			int out = 0;
			int[] players = new int[3];
			while (out < 3) {
				// 몇루타 계산
				int hit = arr[i][batting_order[index]];
				// 아웃 일때
				if (hit == 0) {
					out++;
					index++;
					index %= 9;
					continue;
				}
				//공을 친것에 대한 플레이어들의 이동
				int lastPlayer = players[2];
				players[2] = players[1];
				players[1] = players[0];
				players[0] = 1;
				if (lastPlayer == 1)
					score++;
				for (int j = 0; j < hit - 1; j++) {
					lastPlayer = players[2];
					players[2] = players[1];
					players[1] = players[0];
					players[0] = 0;
					if (lastPlayer == 1)
						score++;
				}
				index++;
				index %= 9;
			}
		}
		res = Math.max(res, score);
	}
}
