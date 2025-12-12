def check_mountain_number(s):
    n = len(s)
    if n < 3:
        return False

    pivot_index = -1
    
    # Find the end of the strictly increasing sequence (the potential peak)
    i = 0
    while i < n - 1 and s[i] < s[i+1]:
        i += 1
    
    # Check if the increasing part is valid (must be at least one pair of increase)
    # The increasing part must end *before* the last digit
    # If i == 0, it means s[0] is NOT less than s[1], so no increase happened.
    if i == 0:
        return False
        
    pivot_index = i
    
    # The decreasing part must also be valid (must be at least one pair of decrease)
    # The peak cannot be the very last digit
    # The strictly decreasing sequence starts from pivot_index
    j = pivot_index
    while j < n - 1 and s[j] > s[j+1]:
        j += 1
        
    # Check if the decreasing part is valid (must have reached the end)
    # If j is the index of the last digit (n-1), it means the sequence strictly decreased all the way to the end.
    # The decreasing sequence must have at least one decrease, so pivot_index must be less than n-1.
    return j == n - 1 and pivot_index < n - 1

def solve():
    t = int(input())
    for _ in range(t):
        n_str = input()
        
        if check_mountain_number(n_str):
            print("YES")
        else:
            print("NO")

solve()