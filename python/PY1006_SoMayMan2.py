t = int(input())
for _ in range(t):
    n = input()
    if all(c in '47' for c in n):
        print("YES")
    else:
        print("NO")
