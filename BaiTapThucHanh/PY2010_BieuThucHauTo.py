def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def calculate(op, val1, val2):
    if op == '+':
        return val1 + val2
    elif op == '-':
        return val1 - val2
    elif op == '*':
        return val1 * val2
    elif op == '/':
        if val2 == 0:
            raise ZeroDivisionError
        return val1 / val2
    return None

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
            line = input().strip()
        except EOFError:
            break
            
        parts = [part for part in line.split() if part]
        stack = []
        is_valid = True
        
        for token in parts:
            if is_number(token):
                # Xử lý toán hạng (số)
                stack.append(float(token))
            
            elif token in "+-*/":
                # Xử lý toán tử
                if len(stack) < 2:
                    is_valid = False
                    break
                
                operand2 = stack.pop()
                operand1 = stack.pop()
                
                try:
                    result = calculate(token, operand1, operand2)
                    stack.append(result)
                except ZeroDivisionError:
                    is_valid = False
                    break
                
            else:
                # Ký tự không hợp lệ (không phải số, không phải toán tử)
                is_valid = False
                break

        # Kiểm tra tính hợp lệ cuối cùng: Phải còn lại 1 giá trị duy nhất trong stack
        if is_valid and len(stack) == 1:
            final_result = stack.pop()
            # Làm tròn đến 5 chữ số sau dấu phẩy
            print(f"{final_result:.5f}")
        else:
            print("INVALID")

solve()