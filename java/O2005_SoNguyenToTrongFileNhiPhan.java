/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

/**
 *
 * @author admin
 */
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

public class O2005 {

    static boolean[] sieve(int n) {
        boolean[] p = new boolean[n + 1];
        Arrays.fill(p, true);
        p[0] = false; p[1] = false;
        for (int i = 2; i * i <= n; i++) if (p[i]) for (int j = i * i; j <= n; j += i) p[j] = false;
        return p;
    }

    public static void main(String[] args) throws Exception {
        final int LIM = 10000;
        boolean[] isPrime = sieve(LIM - 1);
        int[] freq = new int[LIM];

        ArrayList<Integer> a;
        try (ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream("SONGUYEN.in")))) {
            @SuppressWarnings("unchecked")
            ArrayList<Integer> tmp = (ArrayList<Integer>) ois.readObject();
            a = tmp;
        }

        for (int i = 0, n = a.size(); i < n; i++) {
            int x = a.get(i);
            if (isPrime[x]) freq[x]++;
        }

        StringBuilder sb = new StringBuilder(8192);
        for (int i = 2; i < LIM; i++) if (freq[i] > 0) sb.append(i).append(' ').append(freq[i]).append('\n');
        System.out.print(sb.toString());
    }
}

