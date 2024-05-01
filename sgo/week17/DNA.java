import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    static int N, M, cnt;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] arr = new int[M][24];
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[j][input.charAt(j) - 'A']++;
            }
        }
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int max = 0;
            char now = '.';
            for (int j = 0; j < 24; j++) {
                if (arr[i][j] > max){
                    max = arr[i][j];
                    now = (char)(j + 'A');
                }
            }
            sb.append(now);
            cnt += (N - max);
        }
        System.out.println(sb);
        System.out.println(cnt);
    }
}