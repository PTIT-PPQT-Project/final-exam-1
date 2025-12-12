import sys

def main():
    try:
        n_line = sys.stdin.readline()
        if not n_line:
            return
        n = int(n_line.strip())
        
        k_line = sys.stdin.readline()
        if not k_line:
            return
        k = int(k_line.strip())
        
        filtered_pairs = []
        
        for _ in range(n):
            line = sys.stdin.readline().strip()
            if not line:
                continue
            
            try:
                key, value_str = line.split()
            except ValueError:
                continue
                
            try:
                value_int = int(value_str)
                if value_int > k:
                    filtered_pairs.append(line)
            except ValueError:
                filtered_pairs.append(line)
                
        if not filtered_pairs:
            print("Empty")
        else:
            for pair in filtered_pairs:
                print(pair)
                
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    main()