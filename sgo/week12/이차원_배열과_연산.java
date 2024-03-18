import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int[][] map, cnt;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int width = 3;
        int height = 3;
        int cnt = 0;
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        map = new int[101][101];
        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        while (map[r - 1][c - 1] != k) {
            if (height < width) {
                height = comC();
            } else {
                width = comR();
            }
            cnt++;
            if (cnt > 100)
                break;
        }
        if (cnt > 100)
            System.out.println("-1");
        else
            System.out.println(cnt);
    }

    static int comR() { // 가로로 재정렬 하는 함수
        int len;
        int res = 0;
        cnt = new int[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                cnt[i][map[i][j]]++;
            }
        }
        PriorityQueue<Pair> pq;
        for (int i = 0; i <= 100; i++) {
            int index = 0;
            pq = new PriorityQueue<>();
            for (int j = 0; j < 101; j++) {
                map[i][j] = 0;
                if (cnt[i][j] != 0 && j > 0)
                    pq.add(new Pair(j, cnt[i][j]));
            }
            while (!pq.isEmpty()) {
                Pair pair = pq.poll();
                map[i][index++] = pair.num;
                map[i][index++] = pair.cnt;
            }
            len = 0;
            for (int j = 0; j < 101; j++) {
                if (map[i][j] == 0)
                    break;
                len++;
            }
            res = Math.max(res, len);
        }
        return res;
    }

    static int comC() { // 세로로 재정렬 하는 함수
        int len;
        int res = 0;
        cnt = new int[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                cnt[map[j][i]][i]++;
            }
        }
        PriorityQueue<Pair> pq;
        for (int i = 0; i < 101; i++) {
            int index = 0;
            pq = new PriorityQueue<>();
            for (int j = 0; j < 101; j++) {
                map[j][i] = 0;
                if (cnt[j][i] != 0 && j > 0)
                    pq.add(new Pair(j, cnt[j][i]));
            }
            while (!pq.isEmpty()) {
                Pair pair = pq.poll();
                map[index++][i] = pair.num;
                map[index++][i] = pair.cnt;
            }
            len = 0;
            for (int j = 0; j < 101; j++) {
                if (map[j][i] == 0)
                    break;
                len++;
            }
            res = Math.max(res, len);
        }
        return res;
    }
}

class Pair implements Comparable<Pair>{
    int num;
    int cnt;

    public Pair(int num, int cnt) {
        this.num = num;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.cnt > o.cnt)
            return 1;
        else if (this.cnt == o.cnt)
            return this.num - o.num;
        else
            return -1;
    }
}