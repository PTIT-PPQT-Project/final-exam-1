/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3022 {
    static class MatHang {
        String id, ten, donVi;
        long donGia, soLuong;
        long phiVC, thanhTien, giaBan;

        MatHang(int stt, String ten, String donVi, long donGia, long soLuong) {
            this.id = String.format("MH%02d", stt);
            this.ten = ten.trim();
            this.donVi = donVi.trim();
            this.donGia = donGia;
            this.soLuong = soLuong;

            long tienNhap = donGia * soLuong;                 
            this.phiVC = Math.round(tienNhap * 0.05);         
            this.thanhTien = Math.round(tienNhap + phiVC);    
            this.giaBan = Math.round(thanhTien * 1.02);       
        }

        @Override
        public String toString() {
            return id + " " + ten + " " + donVi + " " + phiVC + " " + thanhTien + " " + giaBan;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        List<MatHang> ds = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String ten = sc.nextLine();
            String donvi = sc.nextLine();
            long dongia = Long.parseLong(sc.nextLine().trim());
            long soluong = Long.parseLong(sc.nextLine().trim());
            ds.add(new MatHang(i, ten, donvi, dongia, soluong));
        }
        StringBuilder sb = new StringBuilder();
        for (MatHang mh : ds) sb.append(mh).append('\n');
        System.out.print(sb.toString());
        sc.close();
    }
    
}
