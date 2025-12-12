import json
import math
from collections import defaultdict

tong_chi_tieu = defaultdict(int)

try:
    with open('data.json', 'r', encoding='utf-8') as f:
        du_lieu_json = json.load(f)
        
        if not isinstance(du_lieu_json, list):
            exit()
            
        for don_hang in du_lieu_json:
            try:
                ten_khach = don_hang.get('customer')
                if not ten_khach:
                    continue
                    
                tong_don_hang_nay = 0
                items_list = don_hang.get('items', [])
                
                for item in items_list:
                    so_luong = int(item.get('quantity', 0))
                    don_gia = int(item.get('unit_price', 0))
                    tong_don_hang_nay += (so_luong * don_gia)
                
                tong_chi_tieu[ten_khach] += tong_don_hang_nay
                
            except (ValueError, TypeError, KeyError):
                pass

except (FileNotFoundError, json.JSONDecodeError):
    pass

danh_sach_sap_xep = sorted(tong_chi_tieu.items(), key=lambda x: x[1], reverse=True)

for ten, tong_tien in danh_sach_sap_xep:
    print(f"{ten} {tong_tien}")