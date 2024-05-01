import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    static int N, S, cnt;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        cnt = 0;
        for (int i = 1; i <= N; i++) {
            com(0, 0, 0, i);
        }

        System.out.println(cnt);
    }

    public static void com (int sum, int d, int start, int max) {
        if (d == max) {
            if (sum == S)
                cnt++;
            return ;
        }
        for (int i = start; i < N; i++) {
            com(sum + arr[i], d + 1, i + 1, max);
        }
    }
}