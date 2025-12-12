import sys

def main():
    try:
        n_line = sys.stdin.readline()
        if not n_line:
            return
            
        n = int(n_line.strip())
        
        pairs = []
        for _ in range(n):
            line = sys.stdin.readline().strip()
            if not line:
                continue
            
            try:
                key, value_str = line.split()
                pairs.append((key, int(value_str)))
            except ValueError:
                continue
                
        pairs.reverse()
        
        for i in range(len(pairs)):
            key, original_value = pairs[i]
            new_position = i + 1
            new_value = original_value * new_position
            print(f"{key} {new_value}")
            
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    main()