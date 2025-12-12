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
public class O3016 {
    public static class GameThu {
        private String ma;
        private String ten;
        private int tongThoiGianChoiPhut; 

        public GameThu(String ma, String ten, String gioVao, String gioRa) {
            this.ma = ma;
            this.ten = ten;
            this.tongThoiGianChoiPhut = tinhThoiGianChoi(gioVao, gioRa);
        }

        private int tinhThoiGianChoi(String gioVao, String gioRa) {
            String[] vaoParts = gioVao.split(":");
            int gioVaoPhut = Integer.parseInt(vaoParts[0]) * 60 + Integer.parseInt(vaoParts[1]);

            String[] raParts = gioRa.split(":");
            int gioRaPhut = Integer.parseInt(raParts[0]) * 60 + Integer.parseInt(raParts[1]);

            return gioRaPhut - gioVaoPhut;
        }

        public int getTongThoiGianChoiPhut() {
            return tongThoiGianChoiPhut;
        }

        private String formatThoiGianChoi() {
            int gio = tongThoiGianChoiPhut / 60;
            int phut = tongThoiGianChoiPhut % 60;
            return gio + " gio " + phut + " phut";
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + formatThoiGianChoi();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());

        List<GameThu> danhSachGameThu = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String ma = scanner.nextLine();
            String ten = scanner.nextLine();
            String gioVao = scanner.nextLine();
            String gioRa = scanner.nextLine();

            danhSachGameThu.add(new GameThu(ma, ten, gioVao, gioRa));
        }

        Collections.sort(danhSachGameThu, 
            Comparator.comparingInt(GameThu::getTongThoiGianChoiPhut).reversed());

        for (GameThu gt : danhSachGameThu) {
            System.out.println(gt);
        }

        scanner.close();
    }
    
}
