import sys

def main():
    try:
        n_q_line = sys.stdin.readline()
        if not n_q_line:
            return
        
        n, q = map(int, n_q_line.split())
        
        stock_totals = {}
        
        for _ in range(n):
            line = sys.stdin.readline().strip()
            if not line:
                continue
            
            try:
                product_name, value_str = line.split()
                value = int(value_str)
                
                if product_name in stock_totals:
                    stock_totals[product_name] += value
                else:
                    stock_totals[product_name] = value
            except ValueError:
                continue
        
        for _ in range(q):
            query_line = sys.stdin.readline().strip()
            if not query_line:
                continue
            
            query_parts = query_line.split()
            
            if len(query_parts) < 2:
                print(0)
                continue
                
            products_to_query = query_parts[1:]
            query_sum = 0
            
            for product in products_to_query:
                query_sum += stock_totals.get(product, 0)
                
            print(query_sum)
            
    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    main()