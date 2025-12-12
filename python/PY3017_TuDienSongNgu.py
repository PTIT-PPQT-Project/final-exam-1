import sys

def ham_chinh():
    try:
        q_dong = sys.stdin.readline()
        if not q_dong:
            return
        q = int(q_dong.strip())
        
        tu_dien = {}
        
        for _ in range(q):
            dong = sys.stdin.readline().strip()
            if not dong:
                continue
            
            cac_phan = dong.split()
            
            if not cac_phan:
                continue
                
            lenh = cac_phan[0]
            
            if lenh == "add":
                if len(cac_phan) >= 3:
                    tu_tieng_anh = cac_phan[1]
                    nghia_tieng_viet = " ".join(cac_phan[2:])
                    tu_dien[tu_tieng_anh] = nghia_tieng_viet
                    
            elif lenh == "find":
                if len(cac_phan) == 2:
                    tu_tieng_anh = cac_phan[1]
                    ket_qua = tu_dien.get(tu_tieng_anh, "Not found")
                    print(ket_qua)

    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()