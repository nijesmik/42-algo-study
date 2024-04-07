import java.util.Scanner;

public class 문서_검색 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String target = sc.nextLine();

        int cnt = 0;
        while (input.contains(target)) {
            cnt++;
            input = input.substring(input.indexOf(target) + target.length());
        }
        System.out.println(cnt);
    }
}