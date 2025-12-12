N = input()

count_4 = N.count('4')
count_7 = N.count('7')

total_lucky_digits = count_4 + count_7

if total_lucky_digits == 4 or total_lucky_digits == 7:
    print("YES")
else:
    print("NO")