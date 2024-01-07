import java.io.*;
import java.util.*;

public class Main {

    static int[][] map = new int[17][17];
    static int[][] visited = new int[17][17];
    static int N, cnt;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        cnt = 0;
        visited[0][0] = 1;
        visited[0][1] = 1;
        dfs(new Pair(1,0,Form.HORIZONTAL));
        System.out.println(cnt);
    }

    public static void dfs(Pair pair){
        if (pair.x == N - 1 && pair.y == N - 1){
            cnt++;
            return ;
        }
        if (pair.form == Form.HORIZONTAL){
            toHorizontal(pair);
            toDiagonal(pair);
        } else if (pair.form == Form.VERTICAL) {
            toVertical(pair);
            toDiagonal(pair);
        } else if (pair.form == Form.DIAGONAL){
            toHorizontal(pair);
            toDiagonal(pair);
            toVertical(pair);
        }
    }

    private static void toHorizontal(Pair pair){
        int nx = pair.x + 1;
        int ny = pair.y;
        if (nx < N && ny < N && ny >= 0 && nx >= 0
                && visited[ny][nx] == 0 &&  map[ny][nx] == 0){
            visited[ny][nx] = 1;
            dfs(new Pair(nx, ny, Form.HORIZONTAL));
            visited[ny][nx] = 0;
        }
    }

    private static void toVertical(Pair pair){
        int nx = pair.x;
        int ny = pair.y + 1;
        if (nx < N && ny < N && ny >= 0 && nx >= 0
                && visited[ny][nx] == 0 &&  map[ny][nx] == 0){
            visited[ny][nx] = 1;
            dfs(new Pair(nx, ny, Form.VERTICAL));
            visited[ny][nx] = 0;
        }
    }

    private static void toDiagonal(Pair pair){
        int nx = pair.x + 1;
        int ny = pair.y + 1;
        if (nx < N && ny < N && ny >= 0 && nx >= 0
                && visited[ny][nx] == 0  && visited[ny][pair.x] == 0 && visited[pair.y][nx] == 0
                && map[ny][nx] == 0 && map[ny][pair.x] == 0 && map[pair.y][nx] == 0){
            visited[ny][nx] = 1; visited[ny][pair.x] = 1; visited[pair.y][nx] = 1;
            dfs(new Pair(nx, ny, Form.DIAGONAL));
            visited[ny][nx] = 0; visited[ny][pair.x] = 0; visited[pair.y][nx] = 0;
        }
    }

}

class Pair{
    int x;
    int y;

    Form form;

    public Pair(int x, int y, Form form) {
        this.x = x;
        this.y = y;
        this.form = form;
    }
}

enum Form{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
}