import java.io.*;
import java.util.*;

public class Main {
    static int[][] map;
    static int[][] visited;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int N, M;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        map = new int[N][M];
        visited = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        int res = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && map[i][j] == 1){
                    cnt++;
                    res = Math.max(res, bfs(j, i));
                }
            }
        }
        System.out.println(cnt);
        System.out.println(res);
    }
    static int bfs(int x, int y){
        int cnt = 1;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x,y));
        visited[y][x] = 1;
        while (!q.isEmpty()){
            Pair pair = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = pair.x + dx[i];
                int ny = pair.y + dy[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (visited[ny][nx] == 0 && map[ny][nx] == 1){
                    visited[ny][nx] = 1;
                    q.add(new Pair(nx, ny));
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}