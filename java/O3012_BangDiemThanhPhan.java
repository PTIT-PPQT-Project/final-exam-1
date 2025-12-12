package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.Locale;
import java.text.DecimalFormat;

public class O3012 {
    
    public static class SinhVien {
        private String maSV;
        private String hoTen;
        private String lop;
        private double diem1;
        private double diem2;
        private double diem3;

        public SinhVien(String maSV, String hoTen, String lop, double diem1, double diem2, double diem3) {
            this.maSV = maSV;
            this.hoTen = hoTen;
            this.lop = lop;
            this.diem1 = diem1;
            this.diem2 = diem2;
            this.diem3 = diem3;
        }

        public String getMaSV() {
            return maSV;
        }

        @Override
        public String toString() {
            DecimalFormat df = new DecimalFormat("0.0");
            
            return maSV + " " + hoTen + " " + lop + " " + 
                   df.format(diem1) + " " + df.format(diem2) + " " + df.format(diem3);
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US); 
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());

        List<SinhVien> danhSachSV = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String maSV = scanner.nextLine();
            String hoTen = scanner.nextLine();
            String lop = scanner.nextLine();
            
            double diem1 = Double.parseDouble(scanner.nextLine());
            double diem2 = Double.parseDouble(scanner.nextLine());
            double diem3 = Double.parseDouble(scanner.nextLine());
            
            danhSachSV.add(new SinhVien(maSV, hoTen, lop, diem1, diem2, diem3));
        }

        Collections.sort(danhSachSV, Comparator.comparing(SinhVien::getMaSV));

        for (int i = 0; i < danhSachSV.size(); i++) {
            System.out.println((i + 1) + " " + danhSachSV.get(i));
        }

        scanner.close();
    }
}