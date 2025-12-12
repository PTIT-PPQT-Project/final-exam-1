import math
import sys

class PhanSo:
    def __init__(self, tu_so, mau_so):
        self.tu_so = tu_so
        self.mau_so = mau_so
    
    def rut_gon(self):
        ucln = math.gcd(self.tu_so, self.mau_so)
        self.tu_so = self.tu_so // ucln
        self.mau_so = self.mau_so // ucln
    
    def __str__(self):
        return f"{self.tu_so}/{self.mau_so}"

def ham_chinh():
    try:
        dong = sys.stdin.readline().strip()
        if not dong:
            return
            
        tu_so, mau_so = map(int, dong.split())
        
        p = PhanSo(tu_so, mau_so)
        
        p.rut_gon()
        
        print(p)
        
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()