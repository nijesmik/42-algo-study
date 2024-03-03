
import java.io.*;
import java.lang.reflect.Parameter;
import java.nio.file.attribute.PosixFileAttributes;
import java.util.*;

import javax.lang.model.type.ArrayType;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String origin = br.readLine();
		int frontLen = 0;
		int index = origin.length() - 1;
		int backLen = 0;
		while (origin.charAt(frontLen) != '*')
			frontLen++;
		while (origin.charAt(index) != '*'){
			index--;
			backLen++;
		}
		StringBuilder sb = new StringBuilder();
		int inputIndex;
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			boolean isSame = true;
			if (input.length() < frontLen + backLen){
				sb.append("NE\n");
				continue;
			}
			index = 0;
			inputIndex = 0;
			for (int j = 0; j < frontLen; j++) {
				if (input.charAt(inputIndex) != origin.charAt(index)){
					sb.append("NE\n");
					isSame = false;
					break;
				}
				index++; inputIndex++;
			}
			if(!isSame)
				continue;
			index = origin.length() - 1;
			inputIndex = input.length() - 1;
			for (int j = 0; j < backLen; j++) {
				if (input.charAt(inputIndex) != origin.charAt(index)) {
					sb.append("NE\n");
					isSame = false;
					break;
				}
				index--; inputIndex--;
			}
			if (!isSame)
				continue;
			sb.append("DA\n");
		}
		System.out.println(sb);
	}
}
