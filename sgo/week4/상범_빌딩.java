import java.io.*;
import java.util.*;

public class Main {
    static char[][][] map;
    static int[][][] visited;
    static int[] dz = {0, 0, 0, 0, 1, -1};
    static int[] dx = {0, 1, 0, -1, 0, 0};
    static int[] dy = {1, 0, -1, 0, 0, 0};
    static Pair start, end;

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        while (true){
            int L = sc.nextInt();
            int R = sc.nextInt();
            int C = sc.nextInt();
            if (L == 0 && R == 0 && C == 0)
                break;
            map = new char[L][R][C];
            visited = new int[L][R][C];
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < R; j++) {
                    String str = sc.next();
                    for (int k = 0; k < C; k++) {
                        char now = str.charAt(k);
                        map[i][j][k] = now;
                        if (now == 'S')
                            start = new Pair(i, j, k, 0);
                        if (now == 'E')
                            end = new Pair(i, j, k, 0);
                    }
                }
            }
            Queue<Pair> q = new LinkedList<>();
            q.add(start);
            visited[start.z][start.y][start.x] = 1;
            boolean isExit = false;
            while (!q.isEmpty()){
                Pair now = q.poll();
                if (now.x == end.x && now.y == end.y && now.z == end.z){
                    sb.append("Escaped in ").append(now.cnt).append(" minute(s).\n");
                    isExit = true;
                    break ;
                }
                for (int i = 0; i < 6; i++) {
                    int nx = now.x + dx[i];
                    int ny = now.y + dy[i];
                    int nz = now.z + dz[i];
                    if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L)
                        continue;
                    if (visited[nz][ny][nx] == 0 && (map[nz][ny][nx] == '.' || map[nz][ny][nx] == 'E')){
                        visited[nz][ny][nx] = 1;
                        q.add(new Pair(nz, ny, nx, now.cnt + 1));
                    }
                }
            }
            if (!isExit)
                sb.append("Trapped!\n");
        }
        System.out.println(sb);
    }
}

class Pair {
    int x;
    int y;

    int z;

    int cnt;

    public Pair(int z, int y, int x, int cnt) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.cnt = cnt;
    }

    @Override
    public String toString() {
        return "Pair{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                ", cnt=" + cnt +
                '}';
    }
}