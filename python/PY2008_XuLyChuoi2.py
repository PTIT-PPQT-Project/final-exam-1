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
            line = input()
        except EOFError:
            break
            
        # Tách chuỗi thành các từ
        words = line.split(' ')
        
        # Đảo ngược thứ tự các từ
        words.reverse()
        
        processed_words = []
        for word in words:
            if word:
                # Đảo ngược từng từ
                reversed_word = word[::-1]
                processed_words.append(reversed_word)
            else:
                # Giữ nguyên khoảng trắng thừa (nếu có)
                processed_words.append('')
                
        # Nối các từ đã xử lý lại bằng khoảng trắng
        result = ' '.join(processed_words)
        print(result)

solve()