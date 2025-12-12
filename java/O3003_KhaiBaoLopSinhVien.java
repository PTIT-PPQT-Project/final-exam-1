/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author admin
 */
public class O3003 {
    public static class SinhVien {
        private String maSV;
        private String hoTen;
        private String gioiTinh;
        private String lop;
        private String email;
        private String soDienThoai;

        public SinhVien(String maSV, String hoTen, String gioiTinh, String lop, String email, String soDienThoai) {
            this.maSV = maSV;
            this.hoTen = hoTen;
            this.gioiTinh = gioiTinh;
            this.lop = lop;
            this.email = email;
            this.soDienThoai = soDienThoai;
        }

        @Override
        public String toString() {
            return maSV + ", " + hoTen + ", " + gioiTinh + ", " + lop + ", " + email + ", " + soDienThoai;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int soLuongSV = 0;
        if (scanner.hasNextLine()) {
            try {
                soLuongSV = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                return; 
            }
        }
        
        List<SinhVien> danhSachSV = new ArrayList<>();

        for (int i = 0; i < soLuongSV; i++) {
            String maSV = scanner.hasNextLine() ? scanner.nextLine() : "";
            String hoTen = scanner.hasNextLine() ? scanner.nextLine() : "";
            String gioiTinh = scanner.hasNextLine() ? scanner.nextLine() : "";
            String lop = scanner.hasNextLine() ? scanner.nextLine() : "";
            String email = scanner.hasNextLine() ? scanner.nextLine() : "";
            String soDienThoai = scanner.hasNextLine() ? scanner.nextLine() : "";

            boolean duLieuHopLe = true;
            
            if (maSV.length() == 0 || maSV.length() > 10) duLieuHopLe = false;
            if (hoTen.length() == 0 || hoTen.length() > 50) duLieuHopLe = false;
            if (!gioiTinh.equals("Nam") && !gioiTinh.equals("Nu")) duLieuHopLe = false; 
            if (lop.length() == 0 || lop.length() > 30) duLieuHopLe = false;
            if (email.length() == 0 || email.length() > 50) duLieuHopLe = false;
            if (soDienThoai.length() == 0 || soDienThoai.length() > 10) duLieuHopLe = false;
            
            if (duLieuHopLe) {
                for (SinhVien sv : danhSachSV) {
                    if (sv.maSV.equals(maSV)) {
                        duLieuHopLe = false; 
                        break;
                    }
                }
            }

            if (duLieuHopLe) {
                SinhVien sv = new SinhVien(maSV, hoTen, gioiTinh, lop, email, soDienThoai);
                danhSachSV.add(sv);
            } 
        }

        for (SinhVien sv : danhSachSV) {
            System.out.println(sv);
        }

        scanner.close();
    }
}
