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
import java.io.FileNotFoundException;
import java.util.*;

public class O2001 {
    public static void main(String[] args) {
        String DATA = "DATA.in";
        try{
            File file = new File(DATA);
            Scanner in = new Scanner(file);
            while (in.hasNextLine()){
                String dong = in.nextLine();
                System.out.println(dong);
            }
        }catch (FileNotFoundException e){
            System.out.println("Khong tim thay file:"+ DATA);
            e.printStackTrace();
        }
    }
 
}
