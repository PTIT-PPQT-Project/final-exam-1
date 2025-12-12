import sys, math

data = sys.stdin.read().strip().split()
if not data:
    sys.exit()
it = iter(data)
t = int(next(it))
eps = 1e-9
out_lines = []
for _ in range(t):
    x1 = float(next(it)); y1 = float(next(it))
    x2 = float(next(it)); y2 = float(next(it))
    x3 = float(next(it)); y3 = float(next(it))
    area2 = abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1))
    if area2 <= eps:
        out_lines.append("INVALID")
        continue
    a = math.hypot(x1 - x2, y1 - y2)
    b = math.hypot(x2 - x3, y2 - y3)
    c = math.hypot(x3 - x1, y3 - y1)
    p = (a + b + c) / 2.0
    val = p * (p - a) * (p - b) * (p - c)
    if val <= 0:
        out_lines.append("INVALID")
    else:
        s = math.sqrt(val)
        out_lines.append(f"{s:.2f}")

print("\n".join(out_lines))
