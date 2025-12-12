t = int(input())
for _ in range(t):
    nums = list(map(int, input().split()))
    k = int(input())
    result = []
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == k:
                a, b = nums[i], nums[j]
                result.append(f"({a}, {b})")
    print(' '.join(result) if result else "NO")
