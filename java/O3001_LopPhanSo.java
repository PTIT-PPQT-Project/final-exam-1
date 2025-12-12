/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baiTap;

import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class O3001 {
    public static class PhanSo {
        private BigInteger tuSo;
        private BigInteger mauSo;

        public PhanSo(BigInteger tuSo, BigInteger mauSo) {
            this.tuSo = tuSo;
            this.mauSo = mauSo;
        }

        public PhanSo rutGon() {
            BigInteger ucln = tuSo.gcd(mauSo);
            BigInteger tuMoi = tuSo.divide(ucln);
            BigInteger mauMoi = mauSo.divide(ucln);

            return new PhanSo(tuMoi, mauMoi);
        }

        @Override
        public String toString() {
            return tuSo + "/" + mauSo;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Đọc tử số và mẫu số, dùng BigInteger vì giá trị có thể lên đến 18 chữ số
        BigInteger tuSo = scanner.nextBigInteger();
        BigInteger mauSo = scanner.nextBigInteger();
        
        scanner.close();

        PhanSo phanSoBanDau = new PhanSo(tuSo, mauSo);
        PhanSo phanSoToiGian = phanSoBanDau.rutGon();

        System.out.println(phanSoToiGian);
    }
    
}
