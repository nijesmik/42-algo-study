
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		String t = br.readLine();
		while (t.length() > s.length()) {
			if (t.charAt(t.length() - 1) == 'A') {
				t = t.substring(0, t.length() - 1);
			}
			else if (t.charAt(t.length() - 1) == 'B') {
				t = t.substring(0, t.length() - 1);
				StringBuilder sb = new StringBuilder(t);
				t = sb.reverse().toString();
			}
			else
				break;
		}
		if (t.equals(s))
			System.out.println("1");
		else
			System.out.println("0");
	}
}
