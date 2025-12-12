/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3015 {
    public static class NhanVien {
        private String maNV;
        private String hoTen;
        private long luongCoBan; 
        private int soNgayCong;
        private String chucVu;

        public NhanVien(String hoTen, long luongCoBan, int soNgayCong, String chucVu) {
            this.maNV = "NV01";
            this.hoTen = hoTen;
            this.luongCoBan = luongCoBan;
            this.soNgayCong = soNgayCong;
            this.chucVu = chucVu;
        }

        public long tinhLuong() {
            return luongCoBan * soNgayCong;
        }

        public long tinhThuong() {
            long tienLuong = tinhLuong();
            if (soNgayCong >= 25) {
                return (long) (tienLuong * 0.20);
            } else if (soNgayCong >= 22) {
                return (long) (tienLuong * 0.10);
            } else {
                return 0;
            }
        }

        public long tinhPhuCap() {
            switch (chucVu) {
                case "GD":
                    return 250000;
                case "PGD":
                    return 200000;
                case "TP":
                    return 180000;
                case "NV":
                    return 150000;
                default:
                    return 0; 
            }
        }

        public long tinhThuNhap() {
            return tinhLuong() + tinhThuong() + tinhPhuCap();
        }

        @Override
        public String toString() {
            
            return maNV + " " + hoTen + " " + tinhLuong() + " " + tinhThuong() + " " + tinhPhuCap() + " " + tinhThuNhap();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String hoTen = scanner.nextLine();
        long luongCoBan = Long.parseLong(scanner.nextLine()); 
        int soNgayCong = Integer.parseInt(scanner.nextLine());
        String chucVu = scanner.nextLine();

        NhanVien nv = new NhanVien(hoTen, luongCoBan, soNgayCong, chucVu);
        
        System.out.println(nv);
        
        scanner.close();
    }
    
}
