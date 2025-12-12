/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3019 {
    static class KH implements Comparable<KH> {
        String id, name, room;
        long days, total;

        KH(int idx, String name, String room, String in, String out, long service) {
            this.id = String.format("KH%02d", idx);
            this.name = name.trim();
            this.room = room.trim();

            DateTimeFormatter f = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            LocalDate dIn  = LocalDate.parse(in.trim(), f);
            LocalDate dOut = LocalDate.parse(out.trim(), f);

            this.days = ChronoUnit.DAYS.between(dIn, dOut) + 1;

            int floor = room.charAt(0) - '0';
            long pricePerDay;
            if (floor == 1) pricePerDay = 25;
            else if (floor == 2) pricePerDay = 34;
            else if (floor == 3) pricePerDay = 50;
            else pricePerDay = 80; 

            this.total = days * pricePerDay + service;
        }

        @Override
        public int compareTo(KH o) {
            if (this.total != o.total) return Long.compare(o.total, this.total); // giảm dần
            return this.id.compareTo(o.id);
        }

        @Override
        public String toString() {
            return id + " " + name + " " + room + " " + days + " " + total;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        List<KH> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String name = sc.nextLine();
            String room = sc.nextLine();
            String in   = sc.nextLine();
            String out  = sc.nextLine();
            long service = Long.parseLong(sc.nextLine().trim());
            list.add(new KH(i, name, room, in, out, service));
        }
        Collections.sort(list);
        StringBuilder sb = new StringBuilder();
        for (KH k : list) sb.append(k).append('\n');
        System.out.print(sb.toString());
        sc.close();
    }
    
}
