package org.example;

import java.io.*;
import java.util.*;

public class Main {
    static long index = 0;
    static long cnt = 0;
    static int N;
    static long X;
    static long[] size, pcnt;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        X = Long.parseLong(st.nextToken());
        size = new long[50];
        size[0] = 1;
        pcnt = new long[50];
        pcnt[0] = 1;
        for (int i = 1; i < 50; i++) {
            size[i] = size[i - 1] * 2 + 3;
            pcnt[i] = pcnt[i - 1] * 2 + 1;
        }
        eatingBugger(N);
        System.out.println(cnt);
    }

    static void eatingBugger(int d){
        if (index == X)
            return;
        if (d == 0){
            index++;
            cnt++;
            return;
        }
        // 번
        index++;
        if (index == X)
            return;
        // n - 1
        if (index + size[d - 1] < X){
            cnt += pcnt[d - 1];
            index += size[d - 1];
        }else {
            eatingBugger(d - 1);
        }
        if (index == X)
            return;
        // 패티
        index++;
        cnt++;
        if (index == X)
            return;
        // n - 1
        if (index + size[d - 1] < X){
            cnt += pcnt[d - 1];
            index += size[d - 1];
        }else {
            eatingBugger(d - 1);
        }
        if (index == X)
            return;
        // 번
        index++;
    }
}
