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
public class O1002 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        in.nextLine();
        while (t-- >0){
            String s = in.nextLine();
            s = s.trim().toLowerCase();
            String[] cacTu = s.split("\\s+");
            StringBuilder ketQua = new StringBuilder();
            for(String tu : cacTu){
                if(!tu.isEmpty()){
                    String chuCaiDau = String.valueOf(tu.charAt(0)).toUpperCase();
                    ketQua.append(chuCaiDau);
                    
                    String phanConLai = tu.substring(1);
                    ketQua.append(phanConLai);
                    
                    ketQua.append(" ");
                }
            }
            System.out.println(ketQua.toString().trim());
        }
        
    }
}
