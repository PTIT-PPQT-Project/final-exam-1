import math

def is_prime(k):
    if k < 2:
        return False
    if k <= 3:
        return True
    if k % 2 == 0 or k % 3 == 0:
        return False
    i = 5
    while i * i <= k:
        if k % i == 0 or k % (i + 2) == 0:
            return False
        i += 6
    return True

def euler_totient(n):
    if n == 1:
        return 1
    result = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    if n > 1:
        result -= result // n
    return result

T = int(input())
for _ in range(T):
    N = int(input())
    K = euler_totient(N)
    if is_prime(K):
        print("YES")
    else:
        print("NO")