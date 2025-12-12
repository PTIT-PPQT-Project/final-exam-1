import json
import math

class DonHang:
    def __init__(self, data_dict):
        self.ngay_giao_dich = data_dict.get('date', '')
        self.tong_so_tien = 0
        
        try:
            danh_sach_hang = data_dict.get('items', [])
            for hang in danh_sach_hang:
                so_luong = int(hang.get('quantity', 0))
                don_gia = int(hang.get('unit_price', 0))
                self.tong_so_tien += (so_luong * don_gia)
        except (ValueError, TypeError):
            self.tong_so_tien = 0

    def __str__(self):
        return f"{self.ngay_giao_dich} {self.tong_so_tien}"

# --- Chuong trinh chinh ---
danh_sach_don_hang = []

try:
    with open('data.json', 'r', encoding='utf-8') as f:
        du_lieu_json = json.load(f)
        
        if not isinstance(du_lieu_json, list):
            exit()
            
        for don_hang_data in du_lieu_json:
            if isinstance(don_hang_data, dict):
                don_hang_moi = DonHang(don_hang_data)
                danh_sach_don_hang.append(don_hang_moi)

except (FileNotFoundError, json.JSONDecodeError, TypeError):
    pass

# Sap xep theo ngay thang tang dan
# Dinh dang YYYY-MM-DD co the sap xep nhu chuoi
danh_sach_da_sap_xep = sorted(danh_sach_don_hang, key=lambda x: x.ngay_giao_dich)

# In ket qua
for dh in danh_sach_da_sap_xep:
    print(dh)