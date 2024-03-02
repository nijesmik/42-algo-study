package week10;
import java.util.Scanner;

public class 한국이_그리울_땐_서버에_접속하지 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[] target = sc.nextLine().split("[* ]");
        while (n-- > 0) {
            String str = sc.nextLine();
            int endIdx = Math.max(str.length() - target[1].length(), target[0].length());
            if (str.indexOf(target[0]) == 0 && str.indexOf(target[1], endIdx) > -1) {
                System.out.println("DA");
            } else {
                System.out.println("NE");
            }
        }
    }
}