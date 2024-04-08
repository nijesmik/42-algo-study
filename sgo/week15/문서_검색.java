
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String tar = br.readLine();
		int i = 0;
		int cnt = 0;
		while (i < input.length()) {
			boolean isSame = true;
			int tmp = i;
			for (int j = 0; j < tar.length(); j++) {
				if (input.charAt(tmp) != tar.charAt(j)) {
					isSame = false;
					break;
				}
				tmp++;
				if (tmp == input.length()) {
					if (j != tar.length() - 1)
						isSame = false;
					break;
				}
			}
			if (isSame) {
				i = tmp;
				cnt++;
			}else
				i++;
		}
		System.out.println(cnt);
	}
}
