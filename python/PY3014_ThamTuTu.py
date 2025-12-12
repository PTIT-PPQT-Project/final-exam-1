import sys

def ham_chinh():
    try:
        n_dong = sys.stdin.readline()
        if not n_dong:
            return
        n = int(n_dong.strip())
        
        bang_tra_cuu = {}
        
        for _ in range(n):
            dong = sys.stdin.readline().strip()
            if not dong:
                continue
            try:
                tu_tat, tu_day_du = dong.split(maxsplit=1)
                bang_tra_cuu[tu_tat] = tu_day_du
            except ValueError:
                continue
        
        m_dong = sys.stdin.readline()
        if not m_dong:
            return
        
        dong_tin_nhan = sys.stdin.readline().strip()
        if not dong_tin_nhan:
            print("")
            return
            
        cac_tu_tin_nhan = dong_tin_nhan.split()
        
        danh_sach_dich = []
        
        for tu in cac_tu_tin_nhan:
            tu_da_dich = bang_tra_cuu.get(tu, tu)
            danh_sach_dich.append(tu_da_dich)
            
        print(" ".join(danh_sach_dich))
        
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()