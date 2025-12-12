import sys

class Rectangle:
    def __init__(self, chieu_dai, chieu_rong, mau_sac):
        try:
            self.chieu_dai = int(chieu_dai)
            self.chieu_rong = int(chieu_rong)
            self.mau_sac = str(mau_sac)
        except ValueError:
            self.chieu_dai = 0
            self.chieu_rong = 0
            self.mau_sac = ""

    def hop_le(self):
        return self.chieu_dai > 0 and self.chieu_rong > 0

    def chu_vi(self):
        return 2 * (self.chieu_dai + self.chieu_rong)
    
    def dien_tich(self):
        return self.chieu_dai * self.chieu_rong
        
    def mau_sac_chuan_hoa(self):
        if not self.mau_sac:
            return ""
        return self.mau_sac[0].upper() + self.mau_sac[1:].lower()

def ham_chinh():
    try:
        dong = sys.stdin.readline().strip()
        if not dong:
            return
            
        cac_phan = dong.split()
        if len(cac_phan) < 3:
            print("INVALID")
            return
            
        dai, rong, mau = cac_phan
        
        hcn = Rectangle(dai, rong, mau)
        
        if hcn.hop_le():
            cv = hcn.chu_vi()
            dt = hcn.dien_tich()
            ms = hcn.mau_sac_chuan_hoa()
            print(f"{cv} {dt} {ms}")
        else:
            print("INVALID")
            
    except EOFError:
        pass
    except Exception:
        print("INVALID")

if __name__ == "__main__":
    ham_chinh()