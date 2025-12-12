/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3017 {
    public static class HoaDon {
        private String maMatHang;
        private String tenMatHang;
        private int soLuongMua;
        private long donGia;
        private long chietKhau;
        private long tongTienThanhToan;

        public HoaDon(String maMatHang, String tenMatHang, int soLuongMua, long donGia, long chietKhau) {
            this.maMatHang = maMatHang;
            this.tenMatHang = tenMatHang;
            this.soLuongMua = soLuongMua;
            this.donGia = donGia;
            this.chietKhau = chietKhau;
            this.tongTienThanhToan = tinhTongTien();
        }
        private long tinhTongTien() {
            long tongTruocChietKhau = donGia * soLuongMua;
            return tongTruocChietKhau - chietKhau;
        }

        public long getTongTienThanhToan() {
            return tongTienThanhToan;
        }

        @Override
        public String toString() {
            return maMatHang + " " + tenMatHang + " " + soLuongMua + " " + donGia + " " + chietKhau + " " + tongTienThanhToan;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());
        
        List<HoaDon> danhSachHoaDon = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String maMatHang = scanner.nextLine();
            String tenMatHang = scanner.nextLine();
            int soLuongMua = Integer.parseInt(scanner.nextLine());
            long donGia = Long.parseLong(scanner.nextLine());
            long chietKhau = Long.parseLong(scanner.nextLine());
            
            danhSachHoaDon.add(new HoaDon(maMatHang, tenMatHang, soLuongMua, donGia, chietKhau));
        }

        Collections.sort(danhSachHoaDon, 
            Comparator.comparingLong(HoaDon::getTongTienThanhToan).reversed());

        for (HoaDon hd : danhSachHoaDon) {
            System.out.println(hd);
        }
        
        scanner.close();
    }
    
}
