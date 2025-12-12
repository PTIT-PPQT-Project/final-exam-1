import sys

def ham_chinh():
    try:
        so_bo_test_dong = sys.stdin.readline()
        if not so_bo_test_dong:
            return
        
        t = int(so_bo_test_dong.strip())
        
        for _ in range(t):
            n_dong = sys.stdin.readline()
            if not n_dong:
                continue
                
            n = int(n_dong.strip())
            
            danh_sach_cap = []
            
            for _ in range(n):
                dong = sys.stdin.readline().strip()
                if not dong:
                    continue
                try:
                    khoa, gia_tri = dong.split()
                    danh_sach_cap.append((khoa, gia_tri))
                except ValueError:
                    continue
            
            danh_sach_cap.sort(key=lambda cap: cap[0])
            
            for khoa, gia_tri in danh_sach_cap:
                print(f"{khoa} {gia_tri}")

    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()