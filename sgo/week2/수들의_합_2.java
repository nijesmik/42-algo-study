import java.io.*;
import java.util.*;

public class 수들의_합_2 {
    static int[] arr = new int[10001];

    static int N, M;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int startIndex = 0;
        int endIndex = 1;
        System.out.println(cntFindM(startIndex, endIndex, 0, 0));
    }

    static int cntFindM(int startIndex, int endIndex, int sum, int cnt){
        if (sum == M)
            cnt++;
        if (N == 1 && arr[0] == M)
            return 1;
        else if (N == 1)
            return 0;
        if (startIndex >= N || endIndex > N)
            return cnt;
        if (endIndex <= startIndex)
            return cntFindM(startIndex, startIndex + 1, 0, cnt);
        if (sum == 0){
            for (int i = startIndex; i < endIndex; i++) {
                sum += arr[i];
            }
        }else if (sum < M){
            sum += arr[endIndex++];
        } else {
            sum -= arr[startIndex++];
            while (sum > M){
                sum -= arr[--endIndex];
            }
        }
        return cntFindM(startIndex, endIndex, sum, cnt);
    }

}