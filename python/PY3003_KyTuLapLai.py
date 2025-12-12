from collections import Counter

s = input()
counter = Counter(s)
printed = set()

for ch in s:
    if counter[ch] > 1 and ch not in printed:
        print(ch, end=' ')
        printed.add(ch)

if not printed:
    print("None")
