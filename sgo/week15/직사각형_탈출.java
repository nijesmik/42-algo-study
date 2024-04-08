import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[][] map, visited;
    static int N, M, H, W, sy, sx, fy, fx;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        visited = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        sy = Integer.parseInt(st.nextToken()) - 1;
        sx = Integer.parseInt(st.nextToken()) - 1;
        fy = Integer.parseInt(st.nextToken()) - 1;
        fx = Integer.parseInt(st.nextToken()) - 1;
        visited[sy][sx] = 1;
        Queue<Pair> q = new LinkedList<>();
        Pair pair =new Pair(sx, sy, 0);
        q.add(pair);
        boolean canGo = false;
        while (!q.isEmpty()) {
            pair = q.poll();
            int x = pair.x;
            int y = pair.y;
            if (y == fy && x == fx) {
                canGo = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < M && ny < N && visited[ny][nx] == 0 && valid(x, y, i)) {
                    visited[ny][nx] = 1;
                    q.add( new Pair(nx, ny, pair.cnt + 1));
                }
            }
        }
        if (canGo)
            System.out.println(pair.cnt);
        else
            System.out.println("-1");

    }

    static boolean valid(int x, int y, int dir) {
        boolean valid = true;
        if (dir == 0) { // 오른쪽으로 이동
            for (int i = 0; i < H; i++) {
                if (y + i < 0 || y + i >= N || x + W < 0 || x + W >= M ) {
                    valid = false;
                    break;
                }
                if (map[y + i][x + W] == 1) {
                    valid = false;
                    break;
                }
            }
        } else if (dir == 1) {
            for (int i = 0; i < H; i++) {
                if (y + i < 0 || y + i >= N || x - 1 < 0 || x - 1 >= M ) {
                    valid = false;
                    break;
                }
                if (map[y + i][x - 1] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        else if (dir == 2){                // 세로로 이동
            for (int i = 0; i < W; i++) {
                if (y + H < 0 || y + H >= N || x + i < 0 || x + i >= M ) {
                    valid = false;
                    break;
                }
                if (map[y + H][x + i] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < W; i++) {
                if (y - 1< 0 || y - 1 >= N || x + i < 0 || x + i >= M ) {
                    valid = false;
                    break;
                }
                if (map[y - 1][x + i] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        return valid;
    }
}

class Pair {
    int x;
    int y;
    int cnt;
    public Pair(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}