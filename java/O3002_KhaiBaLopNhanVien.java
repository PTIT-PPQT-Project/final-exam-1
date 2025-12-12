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
public class O3002 {
    public static class NhanVien {
        private String maNhanVien;
        private String hoTen;
        private String gioiTinh;
        private String ngaySinh;
        private String diaChi;
        private String masoThue;
        private String ngaykyhopDong;

        public NhanVien(String hoTen, String gioiTinh, String ngaySinh, String diaChi, String masoThue, String ngaykyhopDong) {
            this.maNhanVien = "00001"; 
            this.hoTen = hoTen;
            this.gioiTinh = gioiTinh;
            this.ngaySinh = ngaySinh;
            this.diaChi = diaChi;
            this.masoThue = masoThue;
            this.ngaykyhopDong = ngaykyhopDong; 
        }

        @Override
        public String toString() {
            return maNhanVien + " " + hoTen + " " + gioiTinh + " " + ngaySinh + " " + diaChi + " " + masoThue + " " + ngaykyhopDong; 
        }    
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String hoTen = sc.nextLine();
        String gioiTinh = sc.nextLine();
        String ngaySinh = sc.nextLine();
        String diaChi = sc.nextLine();
        String maSoThue = sc.nextLine();
        String ngayKyHopDong = sc.nextLine();
        
        sc.close();
        
        NhanVien nv = new NhanVien(hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKyHopDong);
        System.out.println(nv);
    }
    
}
