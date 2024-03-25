import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int count = 0;
        int plus = 1;
        int num = 10;
        int N = Integer.parseInt(sc.next());
        for(int i=1; i<=N; i++) {
            if(i%num == 0) {
                plus ++;
                num *= 10;
            }
            count += plus;
        }
        System.out.println(count);
    }
}