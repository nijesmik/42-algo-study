import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M, H;
    static int[][] ladder;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 세로선의 개수
        M = Integer.parseInt(st.nextToken()); // 가로선의 개수
        H = Integer.parseInt(st.nextToken()); // 세로선마다 가로선을 놓을 수 있는 위치의 개수

        ladder = new int[H + 1][N + 1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            ladder[r][c] = 1;
        }
        for (int i = 0; i <= 3; i++) {
            comb(1, 0, i);
        }
        System.out.println(-1);

    }

    static void comb(int nr, int cnt, int size) {
        if (cnt == size) {
            if (check()) {
                System.out.println(size);
                System.exit(0);
            }
            return;
        }

        for (int r = nr; r <= H; r++) {
            for (int c = 1; c < N; c++) {
                if (ladder[r][c] == 1)
                    continue;
                if (ladder[r][c - 1] == 1) {
                    continue;
                }
                if (ladder[r][c + 1] == 1) {
                    continue;
                }
                ladder[r][c] = 1;
                comb(r, cnt + 1, size);
                ladder[r][c] = 0;

            }
        }
    }

    static boolean check() {
        for (int i = 1; i <= N; i++) {
            int currPosition = i;
            int start = 1;
            while (start <= H) {
                if (ladder[start][currPosition] == 1) {
                    currPosition++;
                    start++;
                } else if (ladder[start][currPosition - 1] == 1) {
                    currPosition--;
                    start++;
                } else {
                    start++;
                }
            }
            if (i != currPosition)
                return false;
        }

        return true;
    }
}