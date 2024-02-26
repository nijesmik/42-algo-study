import java.util.*;

public class Main{
    static int N;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        char[][] map = new char[N][N];
        for(int i = 0; i < N; i++){
            String str = sc.next();
            for(int j = 0; j < N; j++)
                map[i][j] = str.charAt(j);
        }
        int max =0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j< N - 1; j++){
                if (map[i][j] != map[i][j+1]){
                    ch_right(map,j,i);
                    max = Math.max(max,max_candy(map));
                    ch_right(map,j,i);
                }
            }
        }
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j< N; j++){
                if (map[i][j] != map[i + 1][j]){
                    ch_down(map,j,i);
                    max = Math.max(max,max_candy(map));
                    ch_down(map,j,i);
                }
            }
        }
        System.out.println(max);
    }

    static void ch_right(char[][] map, int x, int y){
        char tmp = map[y][x];
        map[y][x] = map[y][x + 1];
        map[y][x + 1] = tmp;
    }

    static void ch_down(char[][] map, int x, int y){
        char tmp = map[y][x];
        map[y][x] = map[y + 1][x];
        map[y + 1][x] = tmp;
    }

    static int max_candy(char[][] map){
        int max = 0;
        for(int i = 0; i < N; i++){
            char now = map[i][0];
            int cnt = 0;
            for(int j = 0; j < N; j++){
                if (now == map[i][j]){
                    cnt++;
                    max = Math.max(cnt,max);
                }
                else{
                    now = map[i][j];
                    cnt = 1;
                }
            }
        }
        for(int i = 0; i < N; i++){
            char now = map[0][i];
            int cnt = 0;
            for(int j = 0; j < N; j++){
                if (now == map[j][i]){
                    cnt++;
                    max = Math.max(cnt,max);
                }
                else {
                    now = map[j][i];
                    cnt = 1;
                }
            }
        }
        return max;
    }
}