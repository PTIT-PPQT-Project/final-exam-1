import math

class ThiSinh:
    def __init__(self, ho_ten, ngay_sinh, diem1, diem2, diem3):
        self.ho_ten = ho_ten
        self.ngay_sinh = ngay_sinh
        self.diem1 = diem1
        self.diem2 = diem2
        self.diem3 = diem3
        self.tong_diem = diem1 + diem2 + diem3

    def __str__(self):
        # Định dạng tổng điểm với 1 chữ số sau dấu phẩy
        tong_diem_formatted = f"{self.tong_diem:.1f}"
        
        # Trả về chuỗi output theo yêu cầu
        return f"{self.ho_ten} {self.ngay_sinh} {tong_diem_formatted}"

# --- Chương trình chính ---

# Đọc 5 dòng input
try:
    ten = input()
    ns = input()
    d1 = float(input())
    d2 = float(input())
    d3 = float(input())
    
    # Khởi tạo đối tượng ThiSinh
    thi_sinh = ThiSinh(ten, ns, d1, d2, d3)
    
    # In ra thông tin
    # Phương thức __str__ sẽ tự động được gọi khi print
    print(thi_sinh)

except (ValueError, EOFError):
    # Xử lý nếu input không phải là số
    pass