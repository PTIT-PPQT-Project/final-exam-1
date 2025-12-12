import sys

def main():
    try:
        n = int(sys.stdin.readline())
    except ValueError:
        return

    danh_sach = []
    
    for i in range(1, n + 1):
        ten = sys.stdin.readline().strip()
        if len(ten) > 100:
            ten = ten[:100]
            
        try:
            diem_lt = float(sys.stdin.readline())
            diem_th = float(sys.stdin.readline())
        except ValueError:
            diem_lt = 0.0
            diem_th = 0.0

        if diem_lt > 10:
            diem_lt /= 10.0
        if diem_th > 10:
            diem_th /= 10.0
            
        diem_tb = (diem_lt + diem_th) / 2.0
        
        if diem_tb < 5:
            xep_loai = "TRUOT"
        elif diem_tb < 8:
            xep_loai = "CAN NHAC"
        elif diem_tb < 9.5:
            xep_loai = "DAT"
        else:
            xep_loai = "XUAT SAC"
            
        ma_so = f"TS{i:02d}"
        
        sinh_vien = {
            'ma_so': ma_so,
            'ten': ten,
            'diem_tb': diem_tb,
            'xep_loai': xep_loai
        }
        danh_sach.append(sinh_vien)

    danh_sach.sort(key=lambda sv: sv['diem_tb'], reverse=True)

    for sv in danh_sach:
        print(f"{sv['ma_so']} {sv['ten']} {sv['diem_tb']:.2f} {sv['xep_loai']}")

if __name__ == "__main__":
    main()