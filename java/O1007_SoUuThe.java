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
public class O1007 {
    public static boolean isValidNumber(String s) {
        if (s.isEmpty() || s.length() > 1000) return false;
        if (s.charAt(0) == '0') return false;
        for (char c : s.toCharArray()) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = 0;
        if (scanner.hasNextLine()) {
            try {
                t = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                t = 0; 
            }
        }
        
        for (int i = 0; i < t; i++) {
            String n = scanner.hasNextLine() ? scanner.nextLine() : "";
            
            if (!isValidNumber(n)) {
                System.out.println("INVALID");
                continue;
            }
            
            int soChuSo = n.length();
            int soChuSoChan = 0;
            int soChuSoLe = 0;
            
            for (char c : n.toCharArray()) {
                int digit = c - '0';
                if (digit % 2 == 0) {
                    soChuSoChan++;
                } else {
                    soChuSoLe++;
                }
            }
            
            String ketQua = "NO";
            
            if (soChuSo % 2 == 0 && soChuSoChan > soChuSoLe) {
                ketQua = "YES"; 
            } 
            else if (soChuSo % 2 != 0 && soChuSoLe > soChuSoChan) {
                ketQua = "YES";
            }
            
            System.out.println(ketQua);
        }
        
        scanner.close();
    }
    
}
