t = int(input())
city_to_country = {}
for _ in range(t):
    parts = input().split()
    country = parts[0]
    for city in parts[1:]:
        city_to_country[city] = country

q = int(input())
for _ in range(q):
    city = input().strip()
    print(f"{city} {city_to_country[city]}")
