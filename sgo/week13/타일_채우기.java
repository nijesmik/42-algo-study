import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] dp = new int[31];
        dp[2] = 3;
        dp[4] = 11;
        int tmp = 0;
        for (int i = 6; i < 31; i++) {
            if (i % 2 == 0) {
                tmp += dp[i - 4] * 2;
                dp[i] = dp[i - 2] * 3 + tmp + 2;
            }
        }
        System.out.println(dp[N]);
    }
}