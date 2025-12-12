import math

class KhachHang:
    def __init__(self, ma_kh, ten, chi_so_cu, chi_so_moi):
        self.ma_kh = ma_kh
        self.ten = ten
        
        so_m3 = chi_so_moi - chi_so_cu
        
        tien_nuoc = 0
        phu_phi_ti_le = 0
        
        if so_m3 <= 50:
            tien_nuoc = so_m3 * 100
            phu_phi_ti_le = 0.02
        elif so_m3 <= 100:
            tien_nuoc = (50 * 100) + (so_m3 - 50) * 150
            phu_phi_ti_le = 0.03
        else:
            tien_nuoc = (50 * 100) + (50 * 150) + (so_m3 - 100) * 200
            phu_phi_ti_le = 0.05
            
        phu_phi = tien_nuoc * phu_phi_ti_le
        
        self.tong_tien = round(tien_nuoc + phu_phi)

    def __str__(self):
        return f"{self.ma_kh} {self.ten} {int(self.tong_tien)}"

try:
    so_luong = int(input())
except ValueError:
    so_luong = 0

danh_sach_khach_hang = []

for i in range(so_luong):
    try:
        ma_kh = f"KH{i+1:02d}"
        ten = input()
        chi_so_cu = int(input())
        chi_so_moi = int(input())
        
        kh = KhachHang(ma_kh, ten, chi_so_cu, chi_so_moi)
        danh_sach_khach_hang.append(kh)
        
    except (ValueError, EOFError):
        pass

danh_sach_da_sap_xep = sorted(danh_sach_khach_hang, key=lambda x: -x.tong_tien)

for kh in danh_sach_da_sap_xep:
    print(kh)