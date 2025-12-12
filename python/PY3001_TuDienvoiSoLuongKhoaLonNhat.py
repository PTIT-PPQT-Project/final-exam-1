n = int(input())
max_keys = 0

for _ in range(n):
    line = input().strip()
    if line:
        pairs = line.split(",")
        key_count = len(pairs)
        max_keys = max(max_keys, key_count)

print(max_keys)
