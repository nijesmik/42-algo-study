package org.example;

import java.io.*;
import java.util.*;

public class Main {
    static int min;
    static int[] arr;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        min = 200000001;
        int start = 0;
        int end = N - 1;
        int tmp;
        while (start < end){
            tmp = arr[end] + arr[start];
            if (tmp < 0)
                start++;
            if (0 < tmp)
                end--;
            if (Math.abs(min) > Math.abs(tmp))
                min = tmp;
            if (min == 0)
                break;
        }
        System.out.println(min);
    }
}
