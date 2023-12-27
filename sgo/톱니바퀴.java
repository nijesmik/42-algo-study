import java.util.Arrays;
import java.util.Scanner;

public class 톱니바퀴 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] cogwheel1 = sc.nextLine().toCharArray();
        char[] cogwheel2 = sc.nextLine().toCharArray();
        char[] cogwheel3 = sc.nextLine().toCharArray();
        char[] cogwheel4 = sc.nextLine().toCharArray();
        int rot_cnt = sc.nextInt();
        for (int i = 0; i < rot_cnt; i++) {
            int num = sc.nextInt();
            int direct = sc.nextInt();
            boolean first_contact = cogwheel1[2] != cogwheel2[6];
            boolean second_contact = cogwheel2[2] != cogwheel3[6];
            boolean third_contact = cogwheel3[2] != cogwheel4[6];

            if (num == 1){
                cogwheel1 = array_turn(cogwheel1, direct);
                if (first_contact){
                    cogwheel2 = array_turn(cogwheel2, direct * -1);
                    if (second_contact){
                        cogwheel3 = array_turn(cogwheel3, direct);
                        if (third_contact){
                            cogwheel4 = array_turn(cogwheel4, direct * -1);
                        }
                    }
                }
            }
            if (num == 2){
                cogwheel2 = array_turn(cogwheel2, direct);
                if (first_contact){
                    cogwheel1 = array_turn(cogwheel1, direct * -1);
                }
                if (second_contact){
                    cogwheel3 = array_turn(cogwheel3, direct * -1);
                    if (third_contact){
                        cogwheel4 = array_turn(cogwheel4, direct);
                    }
                }
            }
            if (num == 3){
                cogwheel3 = array_turn(cogwheel3, direct);
                if (second_contact){
                    cogwheel2 = array_turn(cogwheel2, direct * -1);
                    if (first_contact){
                        cogwheel1 = array_turn(cogwheel1, direct);
                    }
                }
                if (third_contact){
                    cogwheel4 = array_turn(cogwheel4, direct * -1);
                }
            }
            if (num == 4){
                cogwheel4 = array_turn(cogwheel4, direct);
                if (third_contact){
                    cogwheel3 = array_turn(cogwheel3, direct * -1);
                    if (second_contact){
                        cogwheel2 = array_turn(cogwheel2, direct);
                        if (first_contact){
                            cogwheel1 = array_turn(cogwheel1, direct * -1);
                        }
                    }
                }
            }
        }
        int res = Character.getNumericValue(cogwheel1[0])
                + Character.getNumericValue(cogwheel2[0]) * 2
                + Character.getNumericValue(cogwheel3[0]) * 4
                + Character.getNumericValue(cogwheel4[0]) * 8;
        System.out.println(res);
    }

    public static char[] array_turn(char[] array, int direct){
        char[] res = new char[8];

        if (direct == 1){
            char tmp = array[7];
            for (int i = 1; i < 8; i++) {
                res[i] = array[i - 1];
            }
            res[0] = tmp;
        }
        if (direct == -1){
            char tmp = array[0];
            for (int i = 0; i < 7; i++) {
                res[i] = array[i + 1];
            }
            res[7] = tmp;
        }
        return res;
    }
}