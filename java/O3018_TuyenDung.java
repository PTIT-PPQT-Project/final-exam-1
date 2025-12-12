/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3018 {
    private static double chuanHoaDiem(String diemStr) {
        if (diemStr.equals("10")) {
            return 10.0;
        }
        if (diemStr.length() == 2) {
            try {
                int diemInt = Integer.parseInt(diemStr);
                return (double) diemInt / 10.0;
            } catch (NumberFormatException e) {
                return 0.0; 
            }
        }
        try {
            return Double.parseDouble(diemStr);
        } catch (NumberFormatException e) {
            return 0.0;
        }
    }

    public static class ThiSinh {
        private String maTS;
        private String hoTen;
        private double diemLT;
        private double diemTH;
        private double diemTB; // Điểm trung bình
        private String xepLoai;

        public ThiSinh(int stt, String hoTen, String diemLTStr, String diemTHStr) {
            this.maTS = String.format("TS%02d", stt);
            this.hoTen = hoTen;

            this.diemLT = chuanHoaDiem(diemLTStr);
            this.diemTH = chuanHoaDiem(diemTHStr);

            this.diemTB = (this.diemLT + this.diemTH) / 2.0;


            this.xepLoai = xepLoaiThiSinh(this.diemTB);
        }

        private String xepLoaiThiSinh(double diemTB) {
            if (diemTB > 9.5) {
                return "XUAT SAC";
            } else if (diemTB >= 8.0) { 
                return "DAT";
            } else if (diemTB > 5.0) { 
                return "CAN NHAC";
            } else { 
                return "TRUOT";
            }
        }

        public double getDiemTB() {
            return diemTB;
        }

        @Override
        public String toString() {
            DecimalFormat df = new DecimalFormat("0.00");
            
            return maTS + " " + hoTen + " " + df.format(diemTB) + " " + xepLoai;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());
        
        List<ThiSinh> danhSachThiSinh = new ArrayList<>();
  
        for (int i = 0; i < n; i++) {
            String hoTen = scanner.nextLine();
            String diemLTStr = scanner.nextLine();
            String diemTHStr = scanner.nextLine();
            
            danhSachThiSinh.add(new ThiSinh(i + 1, hoTen, diemLTStr, diemTHStr));
        }

            Collections.sort(danhSachThiSinh, 
            Comparator.comparingDouble(ThiSinh::getDiemTB).reversed());

        for (ThiSinh ts : danhSachThiSinh) {
            System.out.println(ts);
        }
        
        scanner.close();
    }
    
}
