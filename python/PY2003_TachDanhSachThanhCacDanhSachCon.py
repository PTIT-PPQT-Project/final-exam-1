def split_list(lst, k):
    # Nếu k lớn hơn hoặc bằng số phần tử thì INVALID
    if k >= len(lst) or k <= 0:
        return "INVALID"
    
    res = []
    for i in range(0, len(lst), k):
        res.append(lst[i:i+k])
    return " ".join(str(sub) for sub in res)


# Đọc input
t = int(input().strip())   # số test case
for _ in range(t):
    arr = list(map(int, input().split()))
    k = int(input().strip())
    print(split_list(arr, k))
