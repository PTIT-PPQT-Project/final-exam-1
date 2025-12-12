def solve():
    t = int(input())
    for _ in range(t):
        s = input()
        
        if len(s) < 2:
            print("NO")
            continue

        d0 = s[0]
        d1 = s[1]
        
        if d0 == d1:
            print("NO")
            continue
            
        is_beautiful = True
        
        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] != d0:
                    is_beautiful = False
                    break
            else:
                if s[i] != d1:
                    is_beautiful = False
                    break
                    
        if is_beautiful:
            print("YES")
        else:
            print("NO")

solve()