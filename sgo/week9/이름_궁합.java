import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] alpCnt = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
        String A = br.readLine();
        String B = br.readLine();
        ArrayList<Integer> lst = new ArrayList<>();
        for (int i = 0; i < A.length(); i++) {
            lst.add(alpCnt[A.charAt(i) - 'A']);
            lst.add(alpCnt[B.charAt(i) - 'A']);
        }
        while (lst.size() > 2) {
            lst = cal(lst);
        }
        String res = lst.get(0) + String.valueOf(lst.get(1));
        System.out.println(res);
    }

    static ArrayList<Integer> cal (ArrayList<Integer> lst) {
        int index = 0;
        ArrayList<Integer> tmp = new ArrayList<>();
        while (index < lst.size() - 1){
            tmp.add(((lst.get(index) + lst.get(index + 1) ) % 10));
            index++;
        }
        return tmp;
    }
}