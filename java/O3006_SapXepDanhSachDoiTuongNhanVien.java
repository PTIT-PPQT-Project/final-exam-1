package baiTap;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class O3006 {

    public static class NhanVien {
        private String maNV;
        private String hoTen;
        private String gioiTinh;
        private String ngaySinhStr;
        private String diaChi;
        private String maThue;
        private String ngayKyHopDong;
        private Date ngaySinhDate;

        public NhanVien(int stt, String hoTen, String gioiTinh, String ngaySinhStr, String diaChi, String maThue, String ngayKyHopDong) {
            this.maNV = String.format("%05d", stt);
            this.hoTen = hoTen;
            this.gioiTinh = gioiTinh;
            this.ngaySinhStr = ngaySinhStr;
            this.diaChi = diaChi;
            this.maThue = maThue;
            this.ngayKyHopDong = ngayKyHopDong;
            
            try {
                this.ngaySinhDate = new SimpleDateFormat("dd/MM/yyyy").parse(ngaySinhStr);
            } catch (Exception e) {
                this.ngaySinhDate = null;
            }
        }

        public Date getNgaySinhDate() {
            return ngaySinhDate;
        }

        @Override
        public String toString() {
            return maNV + " " + hoTen + " " + gioiTinh + " " + ngaySinhStr + " " + diaChi + " " + maThue + " " + ngayKyHopDong;
        }
    }

    private static boolean isValidDate(String dateStr) {
        if (!dateStr.matches("\\d{2}/\\d{2}/\\d{4}")) return false;
        try {
            new SimpleDateFormat("dd/MM/yyyy").setLenient(false);
            new SimpleDateFormat("dd/MM/yyyy").parse(dateStr);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int soLuongNV = 0;
        if (scanner.hasNextLine()) {
            try {
                soLuongNV = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                return; 
            }
        }
        
        List<NhanVien> danhSachNV = new ArrayList<>();
        
        for (int i = 0; i < soLuongNV; i++) {
            String hoTen = scanner.hasNextLine() ? scanner.nextLine() : "";
            String gioiTinh = scanner.hasNextLine() ? scanner.nextLine() : "";
            String ngaySinhStr = scanner.hasNextLine() ? scanner.nextLine() : "";
            String diaChi = scanner.hasNextLine() ? scanner.nextLine() : "";
            String maThue = scanner.hasNextLine() ? scanner.nextLine() : "";
            String ngayKyHopDong = scanner.hasNextLine() ? scanner.nextLine() : "";

            boolean duLieuHopLe = true;

            if (hoTen.length() == 0 || hoTen.length() > 40) duLieuHopLe = false;
            if (!gioiTinh.equals("Nam") && !gioiTinh.equals("Nu")) duLieuHopLe = false;
            if (!isValidDate(ngaySinhStr)) duLieuHopLe = false;
            if (diaChi.length() == 0 || diaChi.length() > 100) duLieuHopLe = false;
            if (!maThue.matches("\\d{10}")) duLieuHopLe = false;
            if (!isValidDate(ngayKyHopDong)) duLieuHopLe = false;

            if (duLieuHopLe) {
                NhanVien nv = new NhanVien(i + 1, hoTen, gioiTinh, ngaySinhStr, diaChi, maThue, ngayKyHopDong);
                danhSachNV.add(nv);
            } 
        }

        Collections.sort(danhSachNV, new Comparator<NhanVien>() {
            @Override
            public int compare(NhanVien nv1, NhanVien nv2) {
                if (nv1.getNgaySinhDate() == null || nv2.getNgaySinhDate() == null) {
                    return 0; 
                }
                return nv1.getNgaySinhDate().compareTo(nv2.getNgaySinhDate());
            }
        });

        for (NhanVien nv : danhSachNV) {
            System.out.println(nv);
        }

        scanner.close();
    }
}