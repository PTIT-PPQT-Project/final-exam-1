t = int(input())
for _ in range(t):
    n = input()
    count = 0
    while count <= 1000:
        if int(n) % 7 == 0:
            print(n)
            break
        rev = n[::-1]
        n = str(int(n) + int(rev))
        count += 1
    else:
        print(-1)
