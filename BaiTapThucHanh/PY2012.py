def solve():
    try:
        t_line = input()
        if not t_line.strip():
            return
        t = int(t_line.strip())
    except EOFError:
        return
    except ValueError:
        return

    for _ in range(t):
        try:
            n_str = input().strip()
        except EOFError:
            break
            
        if not n_str.isdigit():
            continue

        n = int(n_str)
        s = 0.0
        
        if n % 2 != 0:
            # N is odd: S = 1 + 1/3 + 1/5 + ... + 1/N
            i = 1
            while i <= n:
                s += 1 / i
                i += 2
        else:
            # N is even: S = 1/2 + 1/4 + 1/6 + ... + 1/N
            i = 2
            while i <= n:
                s += 1 / i
                i += 2
        
        # In kết quả với 6 chữ số phần thập phân
        print(f"{s:.6f}")

solve()