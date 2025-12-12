import sys
import json

def get_bmi_status(weight, height):
    if height == 0:
        return "NOT FOUND" 
        
    bmi = weight / (height ** 2)
    
    if bmi < 18.5:
        return 1
    elif bmi < 25:
        return 2
    elif bmi < 30:
        return 3
    else:
        return 4

bmi_data = {}
try:
    with open('datas.json', 'r', encoding='utf-8') as f:
        danh_sach_nguoi = json.load(f)
    
    for person in danh_sach_nguoi:
        try:
            id_num = int(person.get('id', 0))
            weight = float(person.get('weight_kg', 0))
            height = float(person.get('height_m', 0))
            
            if id_num != 0:
                status = get_bmi_status(weight, height)
                bmi_data[id_num] = status
        except (ValueError, TypeError):
            continue

except (FileNotFoundError, json.JSONDecodeError):
    pass

try:
    so_luong_n = int(sys.stdin.readline())
    id_queries = sys.stdin.readline().split()
    
    for id_str in id_queries:
        try:
            id_query = int(id_str)
            if id_query in bmi_data:
                print(f"{id_query} {bmi_data[id_query]}")
            else:
                print(f"{id_query} NOT FOUND")
        except ValueError:
            print(f"{id_str} NOT FOUND")

except (EOFError, ValueError):
    pass