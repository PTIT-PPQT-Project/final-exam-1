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

public class O2003 {
    public static void main(String[] args) {
        try {
            File file = new File("DATA.in");
            Scanner in = new Scanner(file);
            Map<Integer, Integer> soLanXuatHien = new TreeMap<>();
            while (in.hasNextInt()){
                int so = in.nextInt();
                soLanXuatHien.put(so, soLanXuatHien.getOrDefault(so, 0) + 1);
            }
            in.close();
            for(Map.Entry<Integer, Integer> entry : soLanXuatHien.entrySet()){
                System.out.println(entry.getKey()+ " "+ entry.getValue());
            }
        } catch (FileNotFoundException e) {
            System.out.println("Khong tim thay file DATA.in");
        }
    }
    
}
