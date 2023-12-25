package sejinkim;
import java.util.Scanner;

public class 날짜_계산 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int e = sc.nextInt() % 15;
        int s = sc.nextInt() % 28;
        int m = sc.nextInt() % 19;
        int n = 1;
        while (n < 7980) {
            if (n % 15 == e && n % 28 == s && n % 19 == m) break;
            n++;
        }
        System.out.println(n);
    }
}
