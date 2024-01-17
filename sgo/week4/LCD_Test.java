import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb;
    static int top, mid, bot;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String str = sc.next();
        sb = new StringBuilder();
        char[] arr = str.toCharArray();
        int len = arr.length;
        top = 0;
        mid = N + 1;
        bot = 2 * N + 2;
        for (int i = 0; i < 2 * N + 3; i++) {
            for (int j = 0; j < len; j++) {
                if (arr[j] == '0')
                    zero(N, i);
                else if (arr[j] == '1')
                    one(N, i);
                else if (arr[j] == '2')
                    two(N, i);
                else if (arr[j] == '3')
                    three(N, i);
                else if (arr[j] == '4')
                    four(N, i);
                else if (arr[j] == '5')
                    five(N, i);
                else if (arr[j] == '6')
                    six(N, i);
                else if (arr[j] == '7')
                    seven(N, i);
                else if (arr[j] == '8')
                    eight(N, i);
                else if (arr[j] == '9')
                    nine(N, i);
                sb.append(" ");

            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static void printLine(int N, String start, String mid, String end){
        sb.append(start);
        for (int i = 0; i < N; i++) {
            sb.append(mid);
        }
        sb.append(end);
    }
    static void zero(int N, int deep){
        if (deep == top || deep == bot) {
            printLine(N, " ", "-", " ");
        }
        if ((deep > 0 && deep <= mid - 1) || (deep > mid && deep <= bot - 1)){
            printLine(N, "|", " ", "|");
        }
        if (deep == mid)
            printLine(N, " ", " ", " ");
    }

    static void one(int N, int deep) {
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", " ", " ");
        }
        if ((deep > top && deep < mid ) || (deep > mid && deep < bot))
            printLine(N, " ", " ", "|");
    }

    static void two(int N, int deep){
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if (deep > top && deep < mid )
            printLine(N, " ", " ", "|");
        if (deep > mid && deep < bot)
            printLine(N, "|", " ", " ");
    }

    static void three(int N, int deep){
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if ((deep > top && deep < mid ) || (deep > mid && deep < bot))
            printLine(N, " ", " ", "|");
    }

    static void four(int N, int deep){
        if (deep == top || deep == bot){
            printLine(N, " ", " ", " ");
        }
        if (deep > top && deep < mid )
            printLine(N, "|", " ", "|");
        if (deep > mid && deep < bot)
            printLine(N, " ", " ", "|");
        if (deep == mid){
            printLine(N, " ", "-", " ");
        }
    }

    static void five(int N, int deep) {
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if (deep > top && deep < mid )
            printLine(N, "|", " ", " ");
        if (deep > mid && deep < bot)
            printLine(N, " ", " ", "|");
    }

    static void six(int N, int deep){
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if (deep > top && deep < mid )
            printLine(N, "|", " ", " ");
        if (deep > mid && deep < bot)
            printLine(N, "|", " ", "|");
    }

    static void seven(int N, int deep){
        if (deep == top)
            printLine(N, " ", "-", " ");
        if (deep == mid || deep == bot)
            printLine(N, " ", " ", " ");
        if ((deep > top && deep < mid ) || (deep > mid && deep < bot))
            printLine(N, " ", " ", "|");
    }
    static void eight(int N, int deep){
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if ((deep > top && deep < mid ) || (deep > mid && deep < bot))
            printLine(N, "|", " ", "|");
    }
    static void nine(int N, int deep){
        if (deep == top || deep == mid || deep == bot){
            printLine(N, " ", "-", " ");
        }
        if (deep > top && deep < mid )
            printLine(N, "|", " ", "|");
        if (deep > mid && deep < bot)
            printLine(N, " ", " ", "|");
    }
}
