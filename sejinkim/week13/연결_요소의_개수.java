package week13;
import java.util.*;

public class 연결_요소의_개수 {
    static int[] nodes;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), e = sc.nextInt();
        nodes = new int[n+1];
        for (int i = 1; i < n+1; i++) {
            nodes[i] = i;
        }
        for (int i = 0; i < e; i++) {
            union(sc.nextInt(), sc.nextInt());
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (nodes[i] == i) {
                ans++;
            }
        }
        System.out.println(ans);
    }

    static int parent(int a) {
        if (nodes[a] != a) {
            nodes[a] = parent(nodes[a]);
        }
        return nodes[a];
    }

    static void union(int a, int b) {
        nodes[parent(b)] = parent(a);
    }
}