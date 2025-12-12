import math, sys

def khoang(p, q):
    return math.hypot(p[0]-q[0], p[1]-q[1])

def dien_tich(p, q, r):
    return abs((q[0]-p[0])*(r[1]-p[1]) - (q[1]-p[1])*(r[0]-p[0])) / 2.0

data = sys.stdin.read().strip().split()
if not data:
    sys.exit()
it = iter(data)
t = int(next(it))
for _ in range(t):
    x1 = float(next(it)); y1 = float(next(it))
    x2 = float(next(it)); y2 = float(next(it))
    x3 = float(next(it)); y3 = float(next(it))
    A = (x1, y1); B = (x2, y2); C = (x3, y3)
    if dien_tich(A, B, C) <= 1e-9:
        print("INVALID")
    else:
        per = khoang(A, B) + khoang(B, C) + khoang(C, A)
        print(f"{per:.3f}")
