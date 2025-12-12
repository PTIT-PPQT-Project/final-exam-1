package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class O3014 {
    
    static class SV {
        int stt;
        String msv, ten, lop, email, dn;

        SV(int stt, String msv, String ten, String lop, String email, String dn) {
            this.stt = stt;
            this.msv = msv.trim();
            this.ten = ten.trim();
            this.lop = lop.trim();
            this.email = email.trim();
            this.dn = dn.trim();
        }

        @Override
        public String toString() {
            return stt + " " + msv + " " + ten + " " + lop + " " + email + " " + dn;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        List<SV> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String msv = sc.nextLine();
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            String email = sc.nextLine();
            String dn = sc.nextLine();
            list.add(new SV(i, msv, ten, lop, email, dn));
        }

        int q = Integer.parseInt(sc.nextLine().trim());
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < q; i++) {
            String dn = sc.nextLine().trim();
            List<SV> filtered = new ArrayList<>();
            for (SV s : list) if (s.dn.equals(dn)) filtered.add(s);
            filtered.sort(Comparator.comparing(s -> s.ten));
            for (SV s : filtered) out.append(s).append('\n');
        }
        System.out.print(out.toString());
        sc.close();
    }
}