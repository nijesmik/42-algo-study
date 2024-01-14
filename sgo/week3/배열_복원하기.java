import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();

        int[][] map = new int[601][601];
        for (int i = 0; i < H + X; i++) {
            for (int j = 0; j < W + Y; j++) {
                map[i][j] = sc.nextInt();
            }
        }

        int[][] origin = new int[301][301];

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < X || j < Y )
                    origin[i][j] = map[i][j];
                else
                    origin[i][j] = map[i][j] - origin[i - X][j - Y];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.printf(origin[i][j] + " ");
            }
            System.out.println();
        }

    }
}
