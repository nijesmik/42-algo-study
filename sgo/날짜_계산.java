public class 날짜_계산 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int E = sc.nextInt();
        int S = sc.nextInt();
        int M = sc.nextInt();

        int e = 1, s = 1, m = 1, res = 1;
        while(!(e == E && s == S && m == M)){
            e = e % 15 + 1;
            s = s % 28 + 1;
            m = m % 19 + 1;
            res++;
        }
        System.out.println(res);
    }
}