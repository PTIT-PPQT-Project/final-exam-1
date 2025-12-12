import json
import math

class SanPham:
    def __init__(self, ten, gia):
        self.ten = ten
        self.gia = int(gia)

    def __str__(self):
        return f"{self.ten} {self.gia}"

danh_sach_san_pham = []
tong_gia_tri = 0.0

try:
    # Mo va doc file data.json
    with open('data.json', 'r', encoding='utf-8') as f:
        du_lieu = json.load(f)
        
        # Kiem tra xem file co rong khong
        if not du_lieu:
            exit()

        # Duyet qua tung san pham trong file
        for item in du_lieu:
            try:
                # Tao doi tuong SanPham
                sp = SanPham(item['name'], item['price'])
                danh_sach_san_pham.append(sp)
                tong_gia_tri += sp.gia
            except (KeyError, ValueError):
                # Bo qua neu san pham bi loi dinh dang
                pass
    
    # Tinh gia tri trung binh
    if not danh_sach_san_pham:
        exit()
        
    gia_trung_binh = tong_gia_tri / len(danh_sach_san_pham)
    
    # Loc ra danh sach co gia tri thap hon trung binh
    danh_sach_loc = []
    for sp in danh_sach_san_pham:
        if sp.gia < gia_trung_binh:
            danh_sach_loc.append(sp)
            
    # Sap xep danh sach loc
    # Uu tien 1: Sap xep theo gia tang dan (sp.gia)
    # Uu tien 2: Neu gia bang nhau, sap xep theo ten alphaB (sp.ten)
    danh_sach_da_sap_xep = sorted(danh_sach_loc, key=lambda x: (x.gia, x.ten))
    
    # In ket qua
    for sp in danh_sach_da_sap_xep:
        print(sp)

except FileNotFoundError:
    # Thoat neu khong tim thay file
    pass
except (json.JSONDecodeError, ZeroDivisionError):
    # Thoat neu file bi loi hoac rong
    pass