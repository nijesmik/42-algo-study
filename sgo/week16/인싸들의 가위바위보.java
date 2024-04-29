
import java.io.*;
import java.util.*;

public class Main {
	static int N, K;
	static int[][] map;
	static int[][] people;
	static boolean[] visited;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		visited = new boolean[N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		people = new int[3][20];
		for(int i=1; i<3; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<20; j++) {
				people[i][j] = Integer.parseInt(st.nextToken())-1;
			}
		}

		Permutation(0);
		System.out.println(0);
	}

	private static void Permutation(int cnt) {
		if(cnt == N) {
			if(playRockPaperScissors()) {
				System.out.println(1);
				System.exit(0);
			}
			return;
		}

		for(int i=0; i<N; i++) {
			if(visited[i]) continue;
			visited[i] = true;
			people[0][cnt] = i;
			Permutation(cnt+1);
			visited[i] = false;
		}
	}

	private static boolean playRockPaperScissors() {
		// 0 : 지우, 1 : 경희, 2 : 민호
		int p1 = 0;
		int p2 = 1;
		int p3 = 2;
		int[] playerIdx = new int[3];
		int[] winCnt = new int[3];

		while(true) {
			p3 = 3-p1-p2;
			if(winCnt[0] == K) {
				return true;
			}
			if(winCnt[1] == K || winCnt[2] == K) {
				return false;
			}
			if(playerIdx[0] == N || playerIdx[1] == 20 || playerIdx[2] == 20) {
				return false;
			}

			int winnerPlayer = getWinner(p1, p2, playerIdx);
			winCnt[winnerPlayer]++;
			playerIdx[p1]++;
			playerIdx[p2]++;

			p1 = winnerPlayer;
			p2 = p3;
		}
	}

	private static int getWinner(int p1, int p2, int[] idx) {
		int p1Turn = people[p1][idx[p1]];
		int p2Turn = people[p2][idx[p2]];

		if(map[p1Turn][p2Turn] == 2) {
			return p1;
		} else if(map[p1Turn][p2Turn] == 1) {
			return Math.max(p1, p2);
		} else {
			return p2;
		}
	}
}
