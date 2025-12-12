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

public class O2006 {
    static boolean[] sieve(int n){
        boolean[] p=new boolean[n+1];
        Arrays.fill(p,true);
        p[0]=p[1]=false;
        for(int i=2;i*i<=n;i++) if(p[i]) for(int j=i*i;j<=n;j+=i) p[j]=false;
        return p;
    }
    static void countFrom(String path,int[] f) throws Exception{
        try(ObjectInputStream ois=new ObjectInputStream(new BufferedInputStream(new FileInputStream(path)))){
            @SuppressWarnings("unchecked")
            ArrayList<Integer> a=(ArrayList<Integer>) ois.readObject();
            for(int x:a) if(0<=x && x<f.length) f[x]++;
        }
    }
    public static void main(String[] args) throws Exception{
        final int LIM=10000;
        int[] f1=new int[LIM+1], f2=new int[LIM+1];
        boolean[] prime=sieve(LIM);
        countFrom("DATA1.in",f1);
        countFrom("DATA2.in",f2);
        StringBuilder sb=new StringBuilder(8192);
        for(int i=2;i<=LIM;i++){
            if(prime[i] && (f1[i]>0 || f2[i]>0))
                sb.append(i).append(' ').append(f1[i]).append(' ').append(f2[i]).append('\n');
        }
        System.out.print(sb.toString());
    }
}
