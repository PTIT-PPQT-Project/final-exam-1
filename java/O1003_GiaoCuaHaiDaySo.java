/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/**
 *
 * @author admin
 */
public class O1003 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        Set<Integer> tapA = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int so = scanner.nextInt();
            if (so > 0 && so < 1000) {
                tapA.add(so);
            }
        }
        
        Set<Integer> tapB = new HashSet<>();
        for (int i = 0; i < m; i++) {
            int so = scanner.nextInt();
            if (so > 0 && so < 1000) {
                tapB.add(so);
            }
        }
        
        Set<Integer> giaoAB = new TreeSet<>(tapA);
        giaoAB.retainAll(tapB);
        
        for (int so : giaoAB) {
            System.out.print(so + " ");
        }
        System.out.println();
        
        scanner.close();
    }
    
}
