
import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String msg = br.readLine();
		int len = msg.length();
		int R = 0, C = 0;
		for (int i = 1; i <= len / 2; i++) {
			if (len % i == 0){
				if (Math.min(i, len / i) > R){
					R = Math.min(i, len / i);
					C = len / R;
				}
			}
		}

		char[][] arr = new char[R][C];
		int index = 0;
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R; j++) {
				arr[j][i] = msg.charAt(index);
				index++;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				sb.append(arr[i][j]);
			}
		}
		System.out.println(sb);
	}
}
