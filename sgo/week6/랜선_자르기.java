
import java.io.*;
import java.util.*;

public class Main {
    static int[] arr;
    static int K, N;
    static long min, max;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        min = Integer.MAX_VALUE;
        max = 1;
        arr = new int[K];
        for (int i = 0; i < K; i++) {
            arr[i] = sc.nextInt();
            min = Math.min(arr[i], min);
        }
        long start = 1;
        long end = Integer.MAX_VALUE;
        long cnt, mid;
        while (start <= end) {
            cnt = 0;
            mid = (start + end) / 2;
            for (int i = 0; i < K; i++) {
                cnt += arr[i] / mid;
            }
            if (cnt < N)
                end = mid - 1;
            else
                start = mid + 1;
        }
        System.out.println(end);
    }

}
