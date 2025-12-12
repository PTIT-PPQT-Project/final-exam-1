k = int(input())
a = []
for _ in range(k):
    x = int(input())
    if x not in a:
        a.append(x)
print(*a)
