
import java.io.*;
import java.util.*;

public class Main {
	static int[][] map;
	static int N, M, R;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < R; i++) {
			int com = Integer.parseInt(st.nextToken());
			if (com == 1)
				one();
			if (com == 2)
				two();
			if (com == 3)
				three();
			if (com == 4)
				four();
			if (com == 5)
				five();
			if (com == 6)
				six();
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

	static void one () {
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M; j++) {
				int tmp = map[i][j];
				map[i][j] = map[N - 1 - i][j];
				map[N - 1 - i][j] = tmp;
 			}
		}
	}

	static void two () {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				int tmp = map[i][j];
				map[i][j] = map[i][M - 1 - j];
				map[i][M - 1 - j] = tmp;
			}
		}
	}

	static void three () {
		int[][] tmpMap = new int[M][N];

		for(int i=0; i < N; i++){
			for(int j=0; j < M; j++){
				tmpMap[j][N - i - 1] =  map[i][j];
			}
		}

		int tmp = N;
		N = M;
		M = tmp;

		map = tmpMap;
	}

	static void four() {
		int[][] tmpMap = new int[M][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmpMap[M - j - 1][i] = map[i][j];
			}
		}

		int tmp = N;
		N = M;
		M = tmp;

		map = tmpMap;
	}

	static void five() {
		int[][] tmpMap = new int[N][M];

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmpMap[i][j] = map[i + N / 2][j];
			}
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = M / 2; j < M; j++) {
				tmpMap[i][j] = map[i][j - M / 2];
			}
		}

		for (int i = N / 2; i < N; i++) {
			for (int j = M / 2; j < M; j++) {
				tmpMap[i][j] = map[i - N / 2][j];
			}
		}

		for (int i = N / 2; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmpMap[i][j] = map[i][j + M / 2];
			}
		}

		map = tmpMap;
	}
	static void six() {
		int[][] tmpMap = new int[N][M];

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmpMap[i][j] = map[i][j + M / 2];
			}
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = M / 2; j < M; j++) {
				tmpMap[i][j] = map[i + N / 2][j];
			}
		}

		for (int i = N / 2; i < N; i++) {
			for (int j = M / 2; j < M; j++) {
				tmpMap[i][j] = map[i][j - M / 2];
			}
		}

		for (int i = N / 2; i < N; i++) {
			for (int j = 0; j < M / 2; j++) {
				tmpMap[i][j] = map[i - N / 2][j];
			}
		}

		map = tmpMap;
	}
}
