package baiTap;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class O3007 {

    public static class ThiSinh {
        private int maTS;
        private String ten;
        private String ngaySinh;
        private double diem1;
        private double diem2;
        private double diem3;
        private double tongDiem;

        public ThiSinh(int maTS, String ten, String ngaySinh, double diem1, double diem2, double diem3) {
            this.maTS = maTS;
            this.ten = ten;
            this.ngaySinh = ngaySinh;
            this.diem1 = diem1;
            this.diem2 = diem2;
            this.diem3 = diem3;
            this.tongDiem = diem1 + diem2 + diem3;
        }

        public double getTongDiem() {
            return tongDiem;
        }
        
        public int getMaTS() {
            return maTS;
        }

        @Override
        public String toString() {
            String tongDiemFormatted = String.format("%.1f", tongDiem);
            return maTS + " " + ten + " " + ngaySinh + " " + tongDiemFormatted;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int soLuongTS = 0;
        if (scanner.hasNextLine()) {
            try {
                soLuongTS = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                return; 
            }
        }
        
        List<ThiSinh> danhSachTS = new ArrayList<>();
        double diemCaoNhat = -1.0;
        
        for (int i = 0; i < soLuongTS; i++) {
            String ten = scanner.hasNextLine() ? scanner.nextLine() : "";
            String ngaySinh = scanner.hasNextLine() ? scanner.nextLine() : "";
            
            double diem1 = scanner.hasNextLine() ? Double.parseDouble(scanner.nextLine()) : 0.0;
            double diem2 = scanner.hasNextLine() ? Double.parseDouble(scanner.nextLine()) : 0.0;
            double diem3 = scanner.hasNextLine() ? Double.parseDouble(scanner.nextLine()) : 0.0;
            

            ThiSinh ts = new ThiSinh(i + 1, ten, ngaySinh, diem1, diem2, diem3);
            danhSachTS.add(ts);
            

            if (ts.getTongDiem() > diemCaoNhat) {
                diemCaoNhat = ts.getTongDiem();
            }
        }
        
        List<ThiSinh> danhSachThuKhoa = new ArrayList<>();
        for (ThiSinh ts : danhSachTS) {
            if (ts.getTongDiem() == diemCaoNhat) {
                danhSachThuKhoa.add(ts);
            }
        }
        
        Collections.sort(danhSachThuKhoa, new Comparator<ThiSinh>() {
            @Override
            public int compare(ThiSinh ts1, ThiSinh ts2) {
                return Integer.compare(ts1.getMaTS(), ts2.getMaTS());
            }
        });

        for (ThiSinh ts : danhSachThuKhoa) {
            System.out.println(ts);
        }

        scanner.close();
    }
}