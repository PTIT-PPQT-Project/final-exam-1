def decode(s):
    stack = []
    num = 0
    curr = ''
    for c in s:
        if c.isdigit():
            num = num * 10 + int(c)
        elif c == '[':
            stack.append((curr, num))
            curr = ''
            num = 0
        elif c == ']':
            prev, times = stack.pop()
            curr = prev + curr * times
        else:
            curr += c
    return curr

t = int(input())
for _ in range(t):
    s = input().strip()
    print(decode(s))
