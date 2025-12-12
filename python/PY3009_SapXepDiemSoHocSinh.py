import sys

def ham_chinh():
    try:
        so_sinh_vien_dong = sys.stdin.readline()
        if not so_sinh_vien_dong:
            return
            
        n = int(so_sinh_vien_dong.strip())
        
        for _ in range(n):
            ten_sinh_vien = sys.stdin.readline().strip()
            
            so_mon_hoc_dong = sys.stdin.readline()
            if not so_mon_hoc_dong:
                continue
                
            m = int(so_mon_hoc_dong.strip())
            
            danh_sach_mon = []
            
            for _ in range(m):
                dong_diem = sys.stdin.readline().strip()
                if not dong_diem:
                    continue
                
                try:
                    ten_mon, diem_chuoi = dong_diem.split()
                    diem = int(diem_chuoi)
                    danh_sach_mon.append((ten_mon, diem))
                except ValueError:
                    continue
                    
            danh_sach_mon.sort(key=lambda cap_mon: cap_mon[1])
            
            print(ten_sinh_vien)
            for ten_mon, diem in danh_sach_mon:
                print(f"{ten_mon} {diem}")
                
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()