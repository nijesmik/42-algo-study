
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		String[] arr = input.split(":");
		ArrayList<String> strlst = new ArrayList<>();
		StringBuilder sb = new StringBuilder();

		int blankCnt = 0;
		int strCnt = 0;
		for (int i = 0; i < arr.length; i++) {
			if (!Objects.equals(arr[i], "")) {
				strCnt++;
				strlst.add(arr[i]);
			}
			else
				blankCnt++;
		}
		if (blankCnt == 2){
			sb.append("0000");
			for (int i = 1; i < 8 - strCnt; i++) {
				sb.append(":0000");
			}
			for (String now : strlst) {
				sb.append(":").append(addZero(now));
			}
		} else if (input.charAt(input.length() - 1) == ':' && input.charAt(input.length() - 2) == ':'){
			sb.append(addZero(strlst.get(0)));
			for (int i = 1; i < strlst.size(); i++) {
				sb.append(":").append(addZero(strlst.get(i)));
			}
			for (int i = 0; i < 8 - strCnt; i++) {
				sb.append(":0000");
			}
		}else if (blankCnt == 0) {
			sb.append(addZero(strlst.get(0)));
			for (int i = 1; i < 8; i++) {
				sb.append(":").append(addZero(strlst.get(i)));
			}
		} else {
			int index = 0;
			sb.append(addZero(strlst.get(index++)));
			for (int i = 0; i < input.length(); i++) {
				if (input.charAt(i) != ':'){
					continue;
				}
				if (i != input.length() - 1 && input.charAt(i + 1) == ':') {
					sb.append(":0000".repeat(Math.max(0, 8 - strlst.size())));
				}
				else
					sb.append(":").append(addZero(strlst.get(index++)));
			}
		}
		System.out.println(sb);
	}

	private static String addZero(String str) {
		StringBuilder sb = new StringBuilder();
		while (sb.length() < 4){
			if (sb.length() + str.length() < 4)
				sb.append("0");
			else
				sb.append(str);
		}
		return sb.toString();
	}
}
