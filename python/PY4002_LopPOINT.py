import math
import sys

class Diem:
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)
    
    def khoang_cach(self, diem_khac):
        dx = self.x - diem_khac.x
        dy = self.y - diem_khac.y
        return math.sqrt(dx**2 + dy**2)

def ham_chinh():
    try:
        dong_so_test = sys.stdin.readline()
        if not dong_so_test:
            return
        t = int(dong_so_test.strip())
        
        for _ in range(t):
            dong = sys.stdin.readline().strip()
            if not dong:
                continue
            
            try:
                cac_phan = dong.split()
                if len(cac_phan) != 4:
                    continue
                
                x1, y1, x2, y2 = map(float, cac_phan)
                
                diem1 = Diem(x1, y1)
                diem2 = Diem(x2, y2)
                
                kc = diem1.khoang_cach(diem2)
                
                print(f"{kc:.4f}")
                
            except ValueError:
                continue

    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()