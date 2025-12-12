import math

class PhanSo:
    def __init__(self, tu, mau):
        self.tu = tu
        self.mau = mau

    def rut_gon(self):
        ucln = math.gcd(self.tu, self.mau)
        self.tu //= ucln
        self.mau //= ucln
        
        # Dam bao mau so luon duong
        if self.mau < 0:
            self.tu = -self.tu
            self.mau = -self.mau

    def cong(self, phan_so_khac):
        a = self.tu
        b = self.mau
        c = phan_so_khac.tu
        d = phan_so_khac.mau
        
        tu_moi = a * d + c * b
        mau_moi = b * d
        
        ket_qua = PhanSo(tu_moi, mau_moi)
        ket_qua.rut_gon()
        return ket_qua

    def __str__(self):
        if self.mau == 1:
            return str(self.tu)
        else:
            return f"{self.tu}/{self.mau}"

# --- Chuong trinh chinh ---
try:
    so_luong_test = int(input())
except ValueError:
    so_luong_test = 0

ket_qua_list = []

for _ in range(so_luong_test):
    try:
        a, b, c, d = map(int, input().split())
        
        ps1 = PhanSo(a, b)
        ps2 = PhanSo(c, d)
        
        ps_tong = ps1.cong(ps2)
        
        ket_qua_list.append(str(ps_tong))
        
    except (ValueError, EOFError):
        pass

for kq in ket_qua_list:
    print(kq)