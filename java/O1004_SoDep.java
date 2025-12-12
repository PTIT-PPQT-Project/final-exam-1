/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.Scanner;


public class O1004 {
    public static boolean isThuanNghich(String s) {
        StringBuilder sb = new StringBuilder(s);
        String reversed = sb.reverse().toString();
        return s.equals(reversed);
    }

    public static boolean hasAllEvenDigits(String s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int digit = c - '0';
            if (digit % 2 != 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Đọc số bộ test
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
            
            if (isThuanNghich(n) && hasAllEvenDigits(n)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
    
}
