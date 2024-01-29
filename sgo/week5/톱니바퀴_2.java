import java.io.*;
import java.util.*;

public class Main {
    static int[][] cogwheel;
    static int flag;
    public static void main(String[] args) throws IOException {
        int top = 0;
        int right = 2;
        int left = 6;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        cogwheel = new int[1001][8];
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String str = br.readLine();
            for (int j = 0; j < 8; j++) {
                cogwheel[i][j] = Integer.parseInt(String.valueOf(str.charAt(j)));
            }
        }
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            flag = 1;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken()) - 1;
            int dir = Integer.parseInt(st.nextToken());
            int canTurnLeft = index;
            int canTurnRight = index;
            for (int j = index; j > 0 ; j--) {
                if (cogwheel[j][left] == cogwheel[j - 1][right])
                    break;
                canTurnLeft--;
            }
            for (int j = index; j < T - 1; j++) {
                if (cogwheel[j][right] == cogwheel[j + 1][left])
                    break;
                canTurnRight++;
            }
            turn(index, dir);
            for (int j = index - 1; j >= canTurnLeft; j--) {
                turn(j, dir);
            }
            flag = -1;
            for (int j = index + 1; j <= canTurnRight ; j++) {
                turn(j, dir);
            }
        }
        int cnt = 0;
        for (int i = 0; i < T; i++) {
            if (cogwheel[i][top] == 1)
                cnt++;
        }
        System.out.println(cnt);
    }

    static void turn(int index, int dir){
        if (dir * flag == 1){
            int tmp = cogwheel[index][7];
            for (int i = 7; i > 0; i--) {
                cogwheel[index][i] = cogwheel[index][i - 1];
            }
            cogwheel[index][0] = tmp;
        }
        if (dir * flag == -1) {
            int tmp = cogwheel[index][0];
            for (int i = 0; i < 7; i++) {
                cogwheel[index][i] = cogwheel[index][i + 1];
            }
            cogwheel[index][7] = tmp;
        }
        flag *= -1;
    }
}
