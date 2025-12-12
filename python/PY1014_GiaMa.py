t = int(input())
for _ in range(t):
    s = input()
    result = ""
    i = 0
    while i < len(s):
        char = s[i]
        i += 1
        count = int(s[i])
        result += char * count
        i += 1
    print(result)
