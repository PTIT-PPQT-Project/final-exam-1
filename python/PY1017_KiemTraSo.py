t = int(input())
for _ in range(t):
    s = input()
    tong = sum(int(c) for c in s)
    dk1 = tong % 10 == 0
    dk2 = len(set(s)) >= 3
    print("YES" if dk1 and dk2 else "NO")
