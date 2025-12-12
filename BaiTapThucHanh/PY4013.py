import math

# Dinh nghia lop PhanSo
class PhanSo:
    def __init__(self, tu, mau):
        if mau == 0:
            raise ValueError("Mau so khong the bang 0")
        self.tu = tu
        self.mau = mau
        self.rut_gon()

    def rut_gon(self):
        ucln = math.gcd(self.tu, self.mau)
        self.tu //= ucln
        self.mau //= ucln
        
        # Chuan hoa dau
        if self.mau < 0:
            self.tu = -self.tu
            self.mau = -self.mau

    # Su dung __add__ de nap chong toan tu '+'
    def __add__(self, phan_so_khac):
        a = self.tu
        b = self.mau
        c = phan_so_khac.tu
        d = phan_so_khac.mau
        
        tu_moi = a * d + c * b
        mau_moi = b * d
        
        # Tra ve mot doi tuong PhanSo moi la tong
        return PhanSo(tu_moi, mau_moi)

    # Su dung __str__ de dinh nghia cach in
    def __str__(self):
        if self.mau == 1:
            return str(self.tu)
        else:
            return f"{self.tu}/{self.mau}"

# --- Chuong trinh chinh ---

try:
    so_test_case = int(input())
except ValueError:
    so_test_case = 0

ket_qua_cac_test = []

for _ in range(so_test_case):
    try:
        so_luong_phan_so = int(input())
    except ValueError:
        so_luong_phan_so = 0
        
    # Khoi tao tong bang 0 (duoi dang phan so 0/1)
    tong = PhanSo(0, 1)
    
    for _ in range(so_luong_phan_so):
        try:
            a, b = map(int, input().split())
            phan_so_hien_tai = PhanSo(a, b)
            
            # Cong don vao tong
            tong = tong + phan_so_hien_tai
            
        except (ValueError, EOFError):
            continue
            
    ket_qua_cac_test.append(str(tong))

# In tat ca ket qua
for kq in ket_qua_cac_test:
    print(kq)