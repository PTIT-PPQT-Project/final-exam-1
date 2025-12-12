def solve():
    N, K = map(int, input().split())
    pairs = []
    
    for _ in range(N):
        key, value = input().split()
        pairs.append(f"{key}:{value}")
    
    # Chia thành từng nhóm K phần tử
    for i in range(0, N, K):
        group = pairs[i:i+K]
        print(" ".join(group))

# Chạy chương trình
if __name__ == "__main__":
    solve()
