package baiTap;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class O3008 {

    public static class MatHang {
        private int maMatHang;
        private String ten;
        private String nhom;
        private double giaMua;
        private double giaBan;
        private double loiNhuan;

        public MatHang(int maMatHang, String ten, String nhom, double giaMua, double giaBan) {
            this.maMatHang = maMatHang;
            this.ten = ten;
            this.nhom = nhom;
            this.giaMua = giaMua;
            this.giaBan = giaBan;
            this.loiNhuan = giaBan - giaMua;
        }

        public double getLoiNhuan() {
            return loiNhuan;
        }

        @Override
        public String toString() {
            DecimalFormat df = new DecimalFormat("0.00");
            return maMatHang + " " + ten + " " + nhom + " " + df.format(loiNhuan);
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());

        List<MatHang> danhSachMatHang = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            String ten = scanner.nextLine();
            String nhom = scanner.nextLine();
            double giaMua = Double.parseDouble(scanner.nextLine());
            double giaBan = Double.parseDouble(scanner.nextLine());

            danhSachMatHang.add(new MatHang(i, ten, nhom, giaMua, giaBan));
        }

        Collections.sort(danhSachMatHang, Comparator.comparingDouble(MatHang::getLoiNhuan).reversed());

        for (MatHang mh : danhSachMatHang) {
            System.out.println(mh);
        }

        scanner.close();
    }
}