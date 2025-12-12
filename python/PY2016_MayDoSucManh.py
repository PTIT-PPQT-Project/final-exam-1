import sys

def solve():
    try:
        t_line = sys.stdin.readline()
        if not t_line:
            return
        T = int(t_line.strip())
    except EOFError:
        return
    except Exception:
        return

    for _ in range(T):
        try:
            n_line = sys.stdin.readline()
            if not n_line:
                break

            k_line = sys.stdin.readline()
            if not k_line:
                break
            
            power_levels_str = k_line.strip().split()
            # Sử dụng float để xử lý chỉ số 5.8 trong một ví dụ khác (nếu có)
            power_levels = [float(k) for k in power_levels_str]

            output_symbols = []
            device_broken = False
            
            for k in power_levels:
                if device_broken:
                    output_symbols.append("?")
                    continue

                if k > 100000:
                    output_symbols.append("?")
                    device_broken = True
                elif k <= 10:
                    output_symbols.append("N")
                elif k <= 1000:
                    output_symbols.append("S")
                elif k <= 100000:
                    output_symbols.append("SS")
            
            print(" ".join(output_symbols))

        except EOFError:
            break
        except Exception:
            continue

if __name__ == "__main__":
    solve()