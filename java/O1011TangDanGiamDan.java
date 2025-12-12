/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

/**
 *
 * @author admin
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class O1011 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            Set<Integer> evenNumbers = new HashSet<>();
            Set<Integer> oddNumbers = new HashSet<>();
            for (int i = 0; i < n; i++) {
                int num = scanner.nextInt();
                if (num % 2 == 0) {
                    evenNumbers.add(num);
                } else {
                    oddNumbers.add(num);
                }
            }

            List<Integer> sortedEven = new ArrayList<>(evenNumbers);
            Collections.sort(sortedEven);
            for (int i = 0; i < sortedEven.size(); i++) {
                System.out.print(sortedEven.get(i));
                if (i < sortedEven.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();

            List<Integer> sortedOdd = new ArrayList<>(oddNumbers);
            Collections.sort(sortedOdd, Collections.reverseOrder());
            for (int i = 0; i < sortedOdd.size(); i++) {
                System.out.print(sortedOdd.get(i));
                if (i < sortedOdd.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        scanner.close();
    }
}
    

