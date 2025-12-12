/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

/**
 *
 * @author admin
 */
import java.math.BigInteger;
import java.util.*;
public class O1006 {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while ( t-- > 0){
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            BigInteger gcd = a.gcd(b);
            System.out.println(gcd);
        }
    }
}
