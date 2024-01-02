import java.util.Scanner;

public class 늑대와_양 {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) {
        int R,C;
        char[][] map = new char[501][501];

        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        for (int i = 0; i < R; i++) {
            String line = sc.next();
            for (int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] == 'S'){
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny >= 0 && nx >= 0 && ny < R && nx < C){
                            if (map[ny][nx] == 'W'){
                                System.out.println(0);
                                return ;
                            }
                            if (map[ny][nx] == '.'){
                                map[ny][nx] = 'D';
                            }
                        }
                    }
                }
            }
        }
        System.out.println(1);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.printf(String.valueOf(map[i][j]));
            }
            System.out.println();
        }
    }
}