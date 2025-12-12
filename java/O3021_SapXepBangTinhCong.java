/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3021 {
    static class NhanVien implements Comparable<NhanVien> {
        String id, name, pos;
        long basic, days;
        long salary, bonus, allowance, income;

        NhanVien(int stt, String name, long basic, long days, String pos) {
            this.id = String.format("NV%02d", stt);
            this.name = name.trim();
            this.basic = basic;
            this.days = days;
            this.pos = pos.trim();

            this.salary = basic * days;

            if (days >= 25)       this.bonus = salary * 20 / 100;
            else if (days >= 22)  this.bonus = salary * 10 / 100;
            else                  this.bonus = 0;

            if (pos.equals("GD"))       this.allowance = 250000;
            else if (pos.equals("PGD")) this.allowance = 200000;
            else if (pos.equals("TP"))  this.allowance = 180000;
            else                        this.allowance = 150000;

            this.income = salary + bonus + allowance;
        }

        @Override
        public int compareTo(NhanVien o) {
            if (this.income != o.income) return Long.compare(o.income, this.income);
            return this.id.compareTo(o.id);
        }

        @Override
        public String toString() {
            return id + " " + name + " " + salary + " " + bonus + " " + allowance + " " + income;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        List<NhanVien> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String name = sc.nextLine();
            long basic = Long.parseLong(sc.nextLine().trim());
            long days  = Long.parseLong(sc.nextLine().trim());
            String pos = sc.nextLine();
            list.add(new NhanVien(i, name, basic, days, pos));
        }
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (NhanVien nv : list) sb.append(nv).append('\n');
        System.out.print(sb.toString());
        sc.close();
    }
    
}
