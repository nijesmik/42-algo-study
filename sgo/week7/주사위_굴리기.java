package org.example;

import java.io.*;
import java.util.*;

public class Main {
	static int[][] dice = new int[3][3];
	static int top = 0;
	static int N, M, x, y, K;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < K; i++) {
			int dir = Integer.parseInt(st.nextToken());
			int nx = x + dx[dir - 1];
			int ny = y + dy[dir - 1];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue ;
			if (dir == 1)
				goRight();
			if (dir == 2)
				goLeft();
			if (dir == 3)
				goUp();
			if (dir == 4)
				goDown();
			if (map[ny][nx] == 0) {
				map[ny][nx] = dice[1][1];
			} else {
				dice[1][1] = map[ny][nx];
				map[ny][nx] = 0;
			}
			x = nx;
			y = ny;
			sb.append(top).append("\n");
		}
		System.out.println(sb);
	}

	static void goRight(){
		int tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = top;
		top = tmp;
	}

	static void goLeft() {
		int tmp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = top;
		top = tmp;
	}

	static void goUp() {
		int tmp = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = top;
		top = tmp;
	}

	static void goDown() {
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = top;
		top = tmp;
	}
}
