import java.io.*;
import java.util.*;

public class Main {
    static int[] dp = new int[20001];
    static List<Pair>[] lst;
    static int start;
    static int inf = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();
        start = sc.nextInt();
        for (int i = 0; i < 20001; i++) {
            dp[i] = inf;
        }
        dp[start] = 0;
        lst = new ArrayList[20001];
        for (int i = 0; i < 20001; i++) {
            lst[i] = new ArrayList<>();
        }
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            lst[u].add(new Pair(u, v, w));
        }
        updateDp();
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (dp[i] == inf && i != start)
                sb.append("INF\n");
            else if (i == start)
                sb.append("0\n");
            else
                sb.append(dp[i]).append("\n");
        }
        System.out.printf(String.valueOf(sb));
    }

    static void updateDp(){
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (Pair pair : lst[start]) {
            if(dp[pair.pstart] != inf && dp[pair.pstart] + pair.weight < dp[pair.end]) {
                dp[pair.end] = dp[pair.pstart] + pair.weight;
                pq.add(pair);
            }
        }
        while (!pq.isEmpty()){
            Pair pqPair = pq.poll();
            List<Pair> nowList = lst[pqPair.end];
            for (Pair pair : nowList){
                if(dp[pair.pstart] != inf && dp[pair.pstart] + pair.weight < dp[pair.end]) {
                    dp[pair.end] = dp[pair.pstart] + pair.weight;
                    pq.add(pair);
                }
            }
        }
    }

}

class Pair implements Comparable<Pair>{
    int pstart;
    int end;
    int weight;

    public Pair(int pstart, int end, int weight) {
        this.pstart = pstart;
        this.end = end;
        this.weight = weight;
    }

    @Override
    public int compareTo(Pair o) {
        return this.weight - o.weight;
    }
}
