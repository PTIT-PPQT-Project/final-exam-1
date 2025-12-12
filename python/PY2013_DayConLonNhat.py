n = int(input())
arr = list(map(int, input().split()))

best = []
current = [arr[0]]

for i in range(1, n):
    if arr[i] > arr[i - 1]:
        current.append(arr[i])
    else:
        if sum(current) > sum(best):
            best = current
        current = [arr[i]]

if sum(current) > sum(best):
    best = current

print(' '.join(map(str, best)))
