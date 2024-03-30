package week02;
import java.util.Scanner;

public class 다음_순열 {
    static int N, arr[];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        int top = N - 1;
        while (top > 0 && arr[top - 1] > arr[top]) {
            top--;
        }
        if (top == 0) {
            System.out.println(-1);
            return;
        }
        int target = N - 1;
        while (arr[top - 1] > arr[target]) {
            target--;
        }
        swap(top - 1, target);
        target = N - 1;
        while (top < target) {
            swap(top++, target--);
        }
        for (int i = 0; i < N; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    static void swap(int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}