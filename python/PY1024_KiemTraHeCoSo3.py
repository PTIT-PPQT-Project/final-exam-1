def check_base3(s):
    valid_digits = {'0', '1', '2'}
    for char in s:
        if char not in valid_digits:
            return False
    return True

def solve():
    t = int(input())
    for _ in range(t):
        s = input()
        if check_base3(s):
            print("YES")
        else:
            print("NO")

solve()