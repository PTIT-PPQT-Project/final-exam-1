from itertools import permutations

def largest_smaller_permutation(num_str):
    num = int(num_str)
    digits = list(num_str)

    # Sinh tất cả hoán vị
    all_perms = set(int("".join(p)) for p in permutations(digits))

    # Lọc các số nhỏ hơn num
    valid = [x for x in all_perms if x < num and str(x)[0] != '0']

    if not valid:
        return "NO"
    return str(max(valid))


# Đọc input
t = int(input().strip())
for _ in range(t):
    N = input().strip()
    print(largest_smaller_permutation(N))
