import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class 치킨_배달 {

    static int[][] map = new int[51][51];
    static List<Pair> homeList = new ArrayList<>();
    static List<Pair> chickList = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int res = 0;
        int N = sc.nextInt();
        int M = sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int chick = sc.nextInt();
                if (chick == 1)
                    homeList.add(new Pair(j,i));
                if (chick == 2)
                    chickList.add(new Pair(j,i));
                map[i][j] = chick;
            }
        }

        res = closechick(0, M, chickList.size(), 0, new ArrayList<Pair>(), 10000000);
        System.out.println(res);
    }

    static int closechick(int start, int M, int size,int d, List<Pair> lst, int min){
        if (d == M){
            return findMinLen(lst);
        }
        for (int i = start; i < size; i++) {
            lst.add(chickList.get(i));
            min = Math.min(closechick(i + 1, M, size, d + 1, lst, min), min);
            lst.remove(lst.size() - 1);
        }
        return min;
    }

    static int findMinLen(List<Pair> lst){
        int res = 0;
        for (Pair home : homeList) {
            int min = 1000000;
            for (Pair chick : lst) {
                int len = Math.abs(home.x - chick.x) + Math.abs(home.y - chick.y);
                if (len < min)
                    min = len;
            }
            res += min;
        }
        return res;
    }
}

class Pair{
    int x;
    int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}