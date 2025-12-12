import math

class HocSinh:
    def __init__(self, ma_hs, ho_ten, diem_list):
        self.ma_hs = ma_hs
        self.ho_ten = ho_ten
        self.diem_list = diem_list
        self.diem_trung_binh = self.tinh_diem_trung_binh()
        self.xep_loai = self.tinh_xep_loai()

    def tinh_diem_trung_binh(self):
        tong_diem = (self.diem_list[0] * 2) + (self.diem_list[1] * 2)
        tong_diem += sum(self.diem_list[2:])
        
        dtb = (tong_diem / 12.0) + 1e-9
        return dtb

    def tinh_xep_loai(self):
        dtb = self.diem_trung_binh
        if dtb >= 9.0:
            return "XUAT SAC"
        elif dtb >= 8.0:
            return "GIOI"
        elif dtb >= 7.0:
            return "KHA"
        elif dtb >= 5.0:
            return "TB"
        else:
            return "YEU"

    def __str__(self):
        dtb_formatted = f"{self.diem_trung_binh:.1f}"
        return f"{self.ma_hs} {self.ho_ten} {dtb_formatted} {self.xep_loai}"

try:
    so_luong = int(input())
except ValueError:
    so_luong = 0

danh_sach_hoc_sinh = []

for i in range(so_luong):
    try:
        ma_hs = f"HS{i+1:02d}"
        ho_ten = input()
        diem_so = list(map(float, input().split()))
        
        if len(diem_so) == 10:
            hoc_sinh = HocSinh(ma_hs, ho_ten, diem_so)
            danh_sach_hoc_sinh.append(hoc_sinh)
            
    except (ValueError, EOFError):
        pass

danh_sach_sap_xep = sorted(danh_sach_hoc_sinh, key=lambda hs: (-hs.diem_trung_binh, hs.ma_hs))

for hs in danh_sach_sap_xep:
    print(hs)