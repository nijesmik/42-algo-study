package sejinkim.week10;
import java.util.*;

public class 차집합 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sizeA = sc.nextInt(), sizeB = sc.nextInt();
        Set<Integer> setA = new TreeSet<>();
        for (int i = 0; i < sizeA; i++) {
            setA.add(sc.nextInt());
        }
        for (int i = 0; i < sizeB; i++) {
            setA.remove(sc.nextInt());
        }
        StringBuilder sb = new StringBuilder();
        sb.append(setA.size() + "\n");
        for (int a : setA) {
            sb.append(a + " ");
        };
        System.out.println(sb);
    }
}