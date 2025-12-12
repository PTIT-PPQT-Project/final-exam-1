from collections import Counter

def solve():
    T = int(input().strip())
    for _ in range(T):
        N = int(input().strip())
        arr = list(map(int, input().split()))
        
        max_val = max(arr)  # M
        freq = Counter(arr)  # Đếm tần suất xuất hiện của từng số trong arr
        
        divisor_count = {}
        
        # Với mỗi số từ 1..M, ta cộng số lượng các bội số của nó
        for k in range(1, max_val + 1):
            total = 0
            for multiple in range(k, max_val + 1, k):
                if multiple in freq:
                    total += freq[multiple]
            if total > 0:
                divisor_count[k] = total
        
        # In ra theo format {a: b, c: d, ...}
        output = ", ".join(f"{key}: {value}" for key, value in divisor_count.items())
        print("{" + output + "}")

# Chạy chương trình
if __name__ == "__main__":
    solve()
