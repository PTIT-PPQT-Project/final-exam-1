/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

/**
 *
 * @author admin
 */
import java.util.*;

public class O1008 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        Set<Character> uniqueChars = new HashSet<>();
        for (char c : s.toCharArray()){
            uniqueChars.add(c);
        }
        System.out.println(uniqueChars.size());
    }
    
}
