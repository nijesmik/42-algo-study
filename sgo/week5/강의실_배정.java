import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            pq.add(new Pair(start, end));
        }
        PriorityQueue<Integer> respq = new PriorityQueue<>();
        respq.add(pq.poll().end);
        while (!pq.isEmpty()) {
            Pair pair = pq.poll();
            if (respq.peek() <= pair.start){
                respq.poll();
                respq.add(pair.end);
            }
            else
                respq.add(pair.end);
        }
        System.out.println(respq.size());
    }
}

class Pair implements Comparable<Pair>{
    int start;
    int end;

    public Pair(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.start < o.start)
            return -1;
        else if (this.start == o.start){
            return this.end - o.end;
        }
        return 1;
    }

}