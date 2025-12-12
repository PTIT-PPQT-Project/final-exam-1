t = int(input())
for _ in range(t):
    n = input()
    if n[:2] == n[-2:]:
        print("YES")
    else:
        print("NO")
