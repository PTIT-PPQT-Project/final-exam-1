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
import java.io.FileInputStream;
import java.io.IOException;
import java.io.DataInputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class O2004 {
    public static void main(String[] args) {
        
        TreeMap<Integer, Integer> tanSuat = new TreeMap<>();
        
        String tenFile = "DATA.IN";

        try (DataInputStream dis = new DataInputStream(new FileInputStream(tenFile))) {
            
            int soLuong = 100000;
            
            for (int i = 0; i < soLuong; i++) {
                
                int so = dis.readInt();
                
                tanSuat.put(so, tanSuat.getOrDefault(so, 0) + 1);
            }
            
        } catch (IOException e) {
            
            System.err.println("Lỗi đọc file: " + e.getMessage());
            return; 
        }
        
        for (Map.Entry<Integer, Integer> entry : tanSuat.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
    
}
