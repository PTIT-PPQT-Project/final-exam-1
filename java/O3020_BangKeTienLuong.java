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
public class O3020 {
    static class NhanVien {
        String id, name, chucVu;
        long luongNgay, soNgayCong;
        long luongThang, thuong, phuCap, thucLinh;

        NhanVien(int stt, String name, long luongNgay, long soNgayCong, String chucVu) {
            this.id = String.format("NV%02d", stt);
            this.name = name.trim();
            this.luongNgay = luongNgay;
            this.soNgayCong = soNgayCong;
            this.chucVu = chucVu.trim();

            this.luongThang = luongNgay * soNgayCong;

            if (soNgayCong >= 25)      this.thuong = luongThang * 20 / 100;
            else if (soNgayCong >= 22) this.thuong = luongThang * 10 / 100;
            else                       this.thuong = 0;

            if (this.chucVu.equals("GD"))      this.phuCap = 250000;
            else if (this.chucVu.equals("PGD")) this.phuCap = 200000;
            else if (this.chucVu.equals("TP"))  this.phuCap = 180000;
            else                                this.phuCap = 150000;

            this.thucLinh = luongThang + thuong + phuCap;
        }

        @Override
        public String toString() {
            return id + " " + name + " " + luongThang + " " + thuong + " " + phuCap + " " + thucLinh;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        List<NhanVien> ds = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String name = sc.nextLine();
            long luongNgay = Long.parseLong(sc.nextLine().trim());
            long ngayCong = Long.parseLong(sc.nextLine().trim());
            String chucVu = sc.nextLine();
            ds.add(new NhanVien(i, name, luongNgay, ngayCong, chucVu));
        }
        long tong = 0;
        StringBuilder out = new StringBuilder();
        for (NhanVien nv : ds) {
            tong += nv.thucLinh;
            out.append(nv).append('\n');
        }
        out.append("Tong chi phi tien luong: ").append(tong);
        System.out.print(out.toString());
        sc.close();
    }
    
}
