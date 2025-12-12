from itertools import combinations

t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))
    count = 0
    for a, b, c in combinations(arr, 3):
        if a + b > c and a + c > b and b + c > a:
            count += 1
    print(count)
