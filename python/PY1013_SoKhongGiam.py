t = int(input())
for _ in range(t):
    s = input()
    ok = True
    for i in range(len(s) - 1):
        if s[i] > s[i + 1]:
            ok = False
            break
    print("YES" if ok else "NO")
