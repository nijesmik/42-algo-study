
import java.io.*;
import java.util.*;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] origin;
    static int N, M, R, cx, cy;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        R = sc.nextInt();
        origin = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origin[i][j] = sc.nextInt();
            }
        }
		// cx : 테두리의 가로 인덱스, cy : 테두리의 세로 인덱스
		// ex : 4 3 배열일경우 첫 테두리는 cx = 4, cy = 3, 두번째 테두리는 cx = 3, cy = 2
        cx = M; cy = N;
        for (int i = 0; i < Math.min(N, M) / 2; i++) { // 테두리 갯수만큼 for문 돌림 (ex 3 3 이면 테두리 2개)
            // 테두리 별로 회전 횟수 구하기 
			int tmpR = R % (((cy - (N - cy))* 2 + (cx - (M - cx) - 2) * 2));
            for (int j = 0; j < tmpR; j++) {
                rotate();
            }
            cx--;
            cy--;
        }
        printmap();
    }

    static void rotate(){
        int y = N - cy, x = M - cx, dir = 0;
        int tmp = origin[y][x];
        while (true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < M - cx || ny < N - cy || nx >= cx || ny >= cy ) {
                dir = dir + 1;
                if (dir >= 4)
                    break ;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            if (nx == M - cx && ny == N - cy) {
                origin[y][x] = tmp;
                break ;
            }
            origin[y][x] = origin[ny][nx];
            x = nx;
            y = ny;

        }
    }

    static void printmap(){
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                System.out.printf(origin[j][i] + " ");
            }
            System.out.println();
        }
    }
}
