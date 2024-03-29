import java.util.Scanner;

public class 비밀_이메일 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        int n = text.length(), c = (int) Math.sqrt(n);
        while (c > 0) {
            if (n % c == 0) {
                break;
            }
            c--;
        }
        int r = n / c;
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                sb.append(text.charAt(i * c + j));
            }
        }
        System.out.println(sb);
    }
}
