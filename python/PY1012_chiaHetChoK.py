a, k, n = map(int, input().split())
start = ((a // k) + 1) * k
res = []

while start <= n:
    b = start - a
    if b > 0:
        res.append(b)
    start += k

if res:
    print(*res)
else:
    print(-1)
