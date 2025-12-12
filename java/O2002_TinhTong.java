/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

/**
 *
 * @author admin
 */
import java.io.File;
import java.util.*;
public class O2002 {
    public static void main(String[] args) {
        long tong = 0;
        try {
            File file = new File("DATA.in");
            Scanner in = new Scanner(file);
            while(in.hasNext()){
                if(in.hasNextInt()){
                    tong += in.nextInt();
                }else{
                    in.next();
                }
            }
            in.close();
        } catch (Exception e) {
            System.out.println("Khoong timf thayas file DATA.in");
        }
        System.out.println(tong);
    }
    
}
