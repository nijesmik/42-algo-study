import java.io.*;
import java.util.*;

public class 퇴사 {
    static int N;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int[] dp = new int[16];
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int date = sc.nextInt();
            int pay = sc.nextInt();
            if (i + date <= N) {
                dp[i + date] = Math.max(pay + dp[i], dp[i + date]);
            }
            dp[i + 1] = Math.max(dp[i], dp[i + 1]);
        }
        System.out.println(dp[N]);
    }
}
