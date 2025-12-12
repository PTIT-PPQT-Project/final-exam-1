import math
from datetime import datetime

class NguoiChoi:
    def __init__(self, ma, ten, vao, ra):
        self.ma = ma
        self.ten = ten
        self.gio_vao = vao
        self.gio_ra = ra
        self.thoi_gian_choi = self.tinh_thoi_gian()

    def tinh_thoi_gian(self):
        try:
            dinh_dang = "%H:%M"
            t1 = datetime.strptime(self.gio_vao, dinh_dang)
            t2 = datetime.strptime(self.gio_ra, dinh_dang)
            
            khoang_thoi_gian = t2 - t1
            
            return int(khoang_thoi_gian.total_seconds() / 60)
        except ValueError:
            return 0

    def hien_thi(self):
        so_gio = self.thoi_gian_choi // 60
        so_phut = self.thoi_gian_choi % 60
        return f"{self.ma} {self.ten} {so_gio} gio {so_phut} phut"

danh_sach = []
try:
    so_luong = int(input())
except ValueError:
    so_luong = 0

for _ in range(so_luong):
    try:
        ma_so = input()
        ho_ten = input()
        gio_vao = input()
        gio_ra = input()
        
        nguoi_choi = NguoiChoi(ma_so, ho_ten, gio_vao, gio_ra)
        danh_sach.append(nguoi_choi)
    except EOFError:
        pass

danh_sach_sap_xep = sorted(danh_sach, key=lambda x: x.thoi_gian_choi, reverse=True)

for nc in danh_sach_sap_xep:
    print(nc.hien_thi())