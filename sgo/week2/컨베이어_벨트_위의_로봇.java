import java.io.*;
import java.util.*;

public class 컨베이어_벨트_위의_로봇 {
    static int[] arr = new int[201];
    static int[] robots = new int[201];
    static int N,K, upIndex, downIndex;
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        for (int i = 0; i < 2 * N; i++) {
             arr[i] = sc.nextInt();
        }
        upIndex = 0;
        downIndex = N - 1;
        int i = 1;
        while (true){
            moveContainer();
            moveRobot();
            upRobot();

            if (!check())
                break;
            i++;
        }
        System.out.println(i);
    }

    static void moveContainer(){
        if (--upIndex < 0){
            upIndex = 2 * N - 1;
        }
        if (--downIndex < 0){
            downIndex = 2 * N - 1;
        }
        robots[downIndex] = 0;
    }

    static void moveRobot(){
        int i = downIndex;
        while (i != upIndex) {
            i--;
            if (i < 0){
                i = 2 * N - 1;
            }
            int next = i + 1;
            if (next == 2 * N){
                next = 0;
            }

            if (robots[next] == 0 && arr[next] >= 1){
                if (robots[i] == 1) {
                    robots[next] = 1;
                    robots[i] = 0;
                    arr[next]--;
                }
                if (next == downIndex)
                    robots[next] = 0;
            }
        }
    }

    static void upRobot(){
        if (arr[upIndex] != 0){
            arr[upIndex]--;
            robots[upIndex] = 1;
        }
    }

    static boolean check(){
        int cnt = 0;
        for (int i = 0; i < 2 * N; i++) {
            if (arr[i] == 0)
                cnt++;
        }
        return cnt < K;
    }
}