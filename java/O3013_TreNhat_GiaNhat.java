package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class O3013 {
    
    public static class Nguoi {
        private String ten;
        private LocalDate ngaySinh;

        public Nguoi(String ten, LocalDate ngaySinh) {
            this.ten = ten;
            this.ngaySinh = ngaySinh;
        }

        public String getTen() {
            return ten;
        }

        public LocalDate getNgaySinh() {
            return ngaySinh;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());
        
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        
        List<Nguoi> danhSach = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            
            String[] parts = line.split(" ", 2); 
            String ten = parts[0];
            String ngaySinhStr = parts[1];
            
            LocalDate ngaySinh = LocalDate.parse(ngaySinhStr, formatter);
            
            danhSach.add(new Nguoi(ten, ngaySinh));
        }
        
        Collections.sort(danhSach, Comparator.comparing(Nguoi::getNgaySinh));
        
        Nguoi nguoiTreNhat = danhSach.get(danhSach.size() - 1);
        
        Nguoi nguoiGiaNhat = danhSach.get(0);
        
        System.out.println(nguoiTreNhat.getTen());
        System.out.println(nguoiGiaNhat.getTen());
        
        scanner.close();
    }
}