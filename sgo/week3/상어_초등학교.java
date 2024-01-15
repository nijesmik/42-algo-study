import java.io.*;
import java.util.*;

public class Main {
    static int[][] map = new int[21][21];
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int N;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        List<Integer>[] finalPairList = new ArrayList[401];
		// 좋아하는 학생들의 번호와 인접한 빈칸의 개수를 저장
        for (int i = 0; i < N * N; i++) {
            int line = sc.nextInt();
            List<Integer> lst = new ArrayList<>();
            for (int j = 0; j < 4; j++) {
                lst.add(sc.nextInt());
            }
            finalPairList[line] = lst;
            List<Pair> pairList = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (map[j][k] == 0)
                        pairList.add(checkSeat(k, j, lst));
                }
            }

            pairList.sort(Comparator.reverseOrder());
            Pair choice = pairList.get(0);
            map[choice.y][choice.x] = line;
        }
        int res = 0;
		// 만족도 계산
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int now = map[i][j];
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < N){
                        for (int friend : finalPairList[now]){
                            if (friend == map[ny][nx]){
                                cnt++;
                            }
                        }
                    }
                }
                if (cnt == 1)
                    res += 1;
                if (cnt == 2)
                    res += 10;
                if (cnt == 3)
                    res += 100;
                if (cnt == 4)
                    res += 1000;
            }
        }
        System.out.println(res);
    }

	// 인접한 칸에 좋아하는 학생이 몇명 있는지, 빈칸이 몇개 있는지 확인
    static Pair checkSeat(int x, int y, List<Integer> lst){
        Pair pair = new Pair(x, y);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N){
                if (checkFavorite(nx, ny, lst))
                    pair.addFavorite();
                if (map[ny][nx] == 0)
                    pair.addBlank();
            }
        }
        return pair;
    }

	// 좋아하는 학생인지 확인
    static boolean checkFavorite(int x, int y, List<Integer> lst){
        for (int friend : lst) {
            if (map[y][x] == friend)
                return true;
        }
        return false;
    }
}

class Pair implements Comparable<Pair>{
    int x;
    int y;
    int favorite;
    int blank;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
        this.favorite = 0;
        this.blank = 0;
    }

    public void addFavorite(){
        this.favorite++;
    }

    public void addBlank(){
        this.blank++;
    }

	// 좋아하는 학생이 많은 순서대로, 빈칸이 많은 순서대로, y가 작은 순서대로, x가 작은 순서대로 정렬
    @Override
    public int compareTo(Pair o) {
        int favoriteComparison = Integer.compare(this.favorite, o.favorite);
        if (favoriteComparison != 0) {
            return favoriteComparison;
        }

        // blank 비교
        int blankComparison = Integer.compare(this.blank, o.blank);
        if (blankComparison != 0) {
            return blankComparison;
        }

        // y 비교
        int yComparison = Integer.compare(o.y, this.y);
        if (yComparison != 0) {
            return yComparison;
        }

        // x 비교
        return Integer.compare(o.x, this.x);
    }
}
