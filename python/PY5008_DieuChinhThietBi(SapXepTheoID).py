import sys
import json

devices_list = []
try:
    with open('datas.json', 'r', encoding='utf-8') as f:
        data = json.load(f)
        devices_list = data.get('devices', [])
except (FileNotFoundError, json.JSONDecodeError):
    pass 

devices_list.sort(key=lambda x: x.get('id', float('inf')))

try:
    t = int(sys.stdin.readline())
except (EOFError, ValueError):
    t = 0

for i in range(t):
    try:
        line = sys.stdin.readline().split()
        if not line:
            break
        
        T_chuan = float(line[0])
        D_chuan = float(line[1])
        A_chuan = float(line[2])

        for device in devices_list:
            current_id = device.get('id', 0)
            current_T = float(device.get('nhiet_do', 0))
            current_D = float(device.get('do_am', 0))
            current_A = float(device.get('anh_sang', 0))
            
            delta_T = T_chuan - current_T
            delta_D = D_chuan - current_D
            delta_A = A_chuan - current_A
            
            print(f"{current_id} {delta_T:.1f} {delta_D:.1f} {delta_A:.1f}")

        if i < t - 1:
            print()

    except (EOFError, ValueError, IndexError):
        break