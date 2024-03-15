
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		boolean isJava = false;
		boolean isCPP = false;
		boolean isError = false;

		for (int i = 0; i < input.length(); i++) {
			if (Character.isUpperCase(input.charAt(i))) {
				isJava = true;
				if (i == 0) {
					isError = true;
					break;
				}
			}
			else if (input.charAt(i) == '_') {
				isCPP = true;
				if (i == input.length() - 1 || i == 0 || input.charAt(i + 1) == '_'){
					isError = true;
					break;
				}
			}
			if (isJava && isCPP) {
				isError = true;
				break;
			}
		}

		StringBuilder sb = new StringBuilder();
		if (!isError) {
			for (int i = 0; i < input.length(); i++) {
				if (Character.isUpperCase(input.charAt(i))) {
					sb.append('_').append(Character.toLowerCase(input.charAt(i)));
				}
				else if (input.charAt(i) == '_') {
					sb.append(Character.toUpperCase(input.charAt(i + 1)));
					i++;
				}
				else {
					sb.append(input.charAt(i));
				}
			}
		}

		if (isError)
			System.out.println("Error!");
		else
			System.out.println(sb);
	}

}
