import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];
        ArrayList<Pair> lst = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                int input = Integer.parseInt(st.nextToken());
                map[i][j] = input;
                if (input == 1)
                    lst.add(new Pair(j, i));
            }
        }
        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int saveLen = 100000;
                for(Pair pair : lst) {
                    int len = 0;
                    int xlen = Math.abs(pair.x - j);
                    int ylen = Math.abs(pair.y - i);
                    while (xlen > 0 || ylen > 0) {
                        xlen--; ylen--; len++;
                    }
                    while (xlen > 0) {
                        xlen--;
                        len++;
                    }
                    while (ylen > 0) {
                        ylen--;
                        len++;
                    }
                    saveLen = Math.min(len, saveLen);
                }
                max = Math.max(max, saveLen);
            }
        }

        System.out.println(max);
    }
}

class Pair {
    int x;
    int y;

    public Pair (int x, int y) {
        this.x = x;
        this.y = y;
    }
}