package baiTap;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class SinhVien {
    private String maSV;
    private String hoTen;
    private String lop;
    private String email;

    public SinhVien(String maSV, String hoTen, String lop, String email) {
        this.maSV = maSV;
        this.hoTen = hoTen;
        this.lop = lop;
        this.email = email;
    }

    public String getLop() {
        return lop;
    }

    public String getMaSV() {
        return maSV;
    }

    @Override
    public String toString() {
        return maSV + " " + hoTen + " " + lop + " " + email;
    }
}

public class O3010 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = Integer.parseInt(scanner.nextLine());

        List<SinhVien> danhSachSV = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String maSV = scanner.nextLine();
            String hoTen = scanner.nextLine();
            String lop = scanner.nextLine();
            String email = scanner.nextLine();
            
            danhSachSV.add(new SinhVien(maSV, hoTen, lop, email));
        }

        Collections.sort(danhSachSV, (sv1, sv2) -> {
            int soSanhLop = sv1.getLop().compareTo(sv2.getLop());
            
            if (soSanhLop != 0) {
                return soSanhLop;
            } else {
                return sv1.getMaSV().compareTo(sv2.getMaSV());
            }
        });

        for (SinhVien sv : danhSachSV) {
            System.out.println(sv);
        }

        scanner.close();
    }
}