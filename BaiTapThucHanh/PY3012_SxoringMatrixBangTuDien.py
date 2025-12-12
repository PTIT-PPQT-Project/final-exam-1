import sys

def ham_chinh():
    try:
        n_dong = sys.stdin.readline()
        if not n_dong:
            return
        n = int(n_dong.strip())
        
        cac_hang_tu = []
        for _ in range(n):
            dong = sys.stdin.readline().strip()
            cac_phan = dong.split()
            if len(cac_phan) > 1:
                cac_hang_tu.append(cac_phan[1:])
            else:
                cac_hang_tu.append([])
        
        m_dong = sys.stdin.readline()
        if not m_dong:
            return
        m = int(m_dong.strip())
        
        bang_diem = {}
        for _ in range(m):
            dong_diem = sys.stdin.readline().strip()
            if not dong_diem:
                continue
            try:
                tu, diem_chuoi = dong_diem.split()
                diem = int(diem_chuoi)
                bang_diem[tu] = diem
            except ValueError:
                continue
                
        ket_qua = []
        for hang in cac_hang_tu:
            tong_diem = 0
            for tu in hang:
                tong_diem += bang_diem.get(tu, 0)
            ket_qua.append(tong_diem)
            
        print(" ".join(map(str, ket_qua)))
        
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()