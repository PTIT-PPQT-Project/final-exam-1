import json
import math

class HocSinh:
    def __init__(self, ten, toan, ly, hoa):
        self.ten = ten
        
        # Công thức: điểm toán * 2 + điểm lý * 1.5 + điểm hóa
        try:
            diem_toan = float(toan)
            diem_ly = float(ly)
            diem_hoa = float(hoa)
            self.diem_xet_tuyen = diem_toan * 2 + diem_ly * 1.5 + diem_hoa
        except ValueError:
            self.diem_xet_tuyen = 0.0

    def __str__(self):
        # Định dạng output theo ví dụ (2 chữ số thập phân)
        return f"{self.ten} {self.diem_xet_tuyen:.2f}"

danh_sach_hoc_sinh = []

# Đọc file data.json
try:
    with open('data.json', 'r', encoding='utf-8') as f:
        du_lieu = json.load(f)
        
        if not du_lieu:
            exit()
            
        # Duyệt qua từng học sinh trong file
        for item in du_lieu:
            try:
                # Lấy thông tin
                ten = item.get('name')
                toan = item.get('math')
                ly = item.get('physics')
                hoa = item.get('chemistry')
                
                # Kiểm tra nếu thiếu thông tin
                if ten is None or toan is None or ly is None or hoa is None:
                    continue
                    
                # Tạo đối tượng HocSinh
                hoc_sinh = HocSinh(ten, toan, ly, hoa)
                danh_sach_hoc_sinh.append(hoc_sinh)
                
            except (KeyError, ValueError, TypeError):
                # Bỏ qua nếu mục dữ liệu bị lỗi
                pass

    # Sắp xếp danh sách
    # key=lambda x: x.diem_xet_tuyen -> sắp xếp theo điểm xét tuyển
    # reverse=True -> sắp xếp giảm dần (từ trên xuống dưới)
    danh_sach_da_sap_xep = sorted(danh_sach_hoc_sinh, key=lambda x: x.diem_xet_tuyen, reverse=True)
    
    # In kết quả
    for hs in danh_sach_da_sap_xep:
        print(hs)

except (FileNotFoundError, json.JSONDecodeError):
    # Thoát nếu file không tồn tại hoặc lỗi JSON
    pass