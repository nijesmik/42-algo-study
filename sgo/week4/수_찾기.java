import java.io.*;
import java.util.*;

public class Main {
    static int[] origin;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        origin = new int[N];
        for (int i = 0; i < N; i++) {
            origin[i] = sc.nextInt();
        }
        Arrays.sort(origin);
        int W = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < W; i++) {
            int target = sc.nextInt();
            if (binarySearch(0, N - 1, target)){
                sb.append(1).append("\n");
            }else{
                sb.append(0).append("\n");
            }
        }
        System.out.println(sb);
    }

    public static boolean binarySearch(int min, int max, int target) {
        if (min > max){
            return false;
        }
        int center = (min + max) / 2;
        if (origin[center] == target)
            return true;
        else if (origin[center] < target)
            return binarySearch(center + 1, max, target);
        else if (origin[center] > target)
            return binarySearch(min, center - 1, target);
        return false;
    }
}
