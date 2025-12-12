import sys

def ham_chinh():
    try:
        n_dong = sys.stdin.readline()
        if not n_dong:
            return
        n = int(n_dong.strip())
        
        tu_dien = {}
        
        for _ in range(n):
            dong = sys.stdin.readline().strip()
            if not dong:
                continue
            try:
                khoa, gia_tri = dong.split()
                tu_dien[khoa] = gia_tri
            except ValueError:
                continue
        
        m_dong = sys.stdin.readline()
        if not m_dong:
            return
        m = int(m_dong.strip())
        
        for _ in range(m):
            dong = sys.stdin.readline().strip()
            if not dong:
                continue
            try:
                khoa, gia_tri = dong.split()
                tu_dien[khoa] = gia_tri
            except ValueError:
                continue
                
        for khoa, gia_tri in tu_dien.items():
            print(f"{khoa} {gia_tri}")
            
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()