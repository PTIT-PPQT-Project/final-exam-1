from collections import Counter

n = int(input())
words = []
for _ in range(n):
    words += input().split()

freq = Counter(words)
sorted_words = sorted(freq.items(), key=lambda x: (-x[1], x[0]))

for word, count in sorted_words[:50]:
    print(f"{word} {count}")
