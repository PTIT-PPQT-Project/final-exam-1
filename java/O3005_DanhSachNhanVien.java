/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class O3005 {
    public static class NhanVien {
        private String maNV;
        private String hoTen;
        private String gioiTinh;
        private String ngaySinh;
        private String diaChi;
        private String maThue;
        private String ngayKyHopDong;

        public NhanVien(int stt, String hoTen, String gioiTinh, String ngaySinh, String diaChi, String maThue, String ngayKyHopDong) {
            this.maNV = String.format("%05d", stt);
            this.hoTen = hoTen;
            this.gioiTinh = gioiTinh;
            this.ngaySinh = ngaySinh;
            this.diaChi = diaChi;
            this.maThue = maThue;
            this.ngayKyHopDong = ngayKyHopDong;
        }

        @Override
        public String toString() {
            return maNV + " " + hoTen + " " + gioiTinh + " " + ngaySinh + " " + diaChi + " " + maThue + " " + ngayKyHopDong;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int soLuongNV = 0;
        if (scanner.hasNextLine()) {
            try {
                soLuongNV = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                return; 
            }
        }
        
        List<NhanVien> danhSachNV = new ArrayList<>();
        
        for (int i = 0; i < soLuongNV; i++) {
            String hoTen = scanner.hasNextLine() ? scanner.nextLine() : "";
            String gioiTinh = scanner.hasNextLine() ? scanner.nextLine() : "";
            String ngaySinh = scanner.hasNextLine() ? scanner.nextLine() : "";
            String diaChi = scanner.hasNextLine() ? scanner.nextLine() : "";
            String maThue = scanner.hasNextLine() ? scanner.nextLine() : "";
            String ngayKyHopDong = scanner.hasNextLine() ? scanner.nextLine() : "";
            
            NhanVien nv = new NhanVien(i + 1, hoTen, gioiTinh, ngaySinh, diaChi, maThue, ngayKyHopDong);
            danhSachNV.add(nv);
        }

        for (NhanVien nv : danhSachNV) {
            System.out.println(nv);
        }

        scanner.close();
    }
    
}
