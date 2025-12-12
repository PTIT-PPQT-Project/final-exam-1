s = input()
lower = sum(1 for c in s if c.islower())
upper = sum(1 for c in s if c.isupper())
print(s.lower() if lower >= upper else s.upper())
