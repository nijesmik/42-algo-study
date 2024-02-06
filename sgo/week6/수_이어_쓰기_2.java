package org.example;

import java.io.*;
import java.util.*;

public class Main {
	static long[] digitSize = new long[11]; // 자리수 별 길이

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextInt();
		long K = sc.nextInt();
		digitSize[1] = 9;
		for (int i = 2; i <= 10; i++) {
            // 자리수 별 길이 저장 ex ) digitSize[1] : 9개 digitSize[2] : digitSize[1] + 90개
			digitSize[i] = (long)(Math.pow(10, i) - Math.pow(10, i - 1)) * i + digitSize[i - 1];
		}
		long len = 0; // N까지 숫자를 표현 할때 길이
		long tmp = N; // tmp N
		int digit = 1; // 자리수
		while (tmp > 0) {
			if (tmp / 10 > 0)
				digit++;
			tmp /= 10;
		}
        //N의 자리수 - 1 까지 길이를 더해 주고 (N이 123이라면 99까지 길이인 digitSize[2]) 
        //N의 자리수에 해당하는 숫자들의 길이를 더해준다 (N이 123이라면 100부터 123까지 총 24개의 숫자를 3 길이 만큼 곱해줌)
		len += digitSize[digit - 1] + (long)((N - Math.pow(10, digit - 1) + 1) * digit);
		if (len < K) { // 길이가 K보다 작으면 -1
			System.out.println("-1");
		} else {
			long res = 0;
			for (int i = 1; i <= 10; i++) {
				if (K <= digitSize[i]) {
					K -= digitSize[i - 1];
                    // K 위치에 해당 하는 숫자를 포함 하는 숫자 가져 오기 :  K위치 숫자가 123에서 2라면 123을 가져옴
					res = (long)Math.pow(10, i - 1) + (K - 1) / i;
                    // K 위치에 해당하는 숫자 뽑기 : K위치 숫자가 123에서 2라면 2를 가져옴
					long dig = (K - 1) % i;
					for (int j = 0; j < i - 1 - dig; j++) {
						res /= 10;
					}
					res %= 10;
					break;
				}
			}
			System.out.println(res);
		}
	}
}
