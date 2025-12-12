a, b = map(int, input().split())
if a <= 0 or b <= 0:
    print(0)
else:
    print(2 * (a + b), a * b)
