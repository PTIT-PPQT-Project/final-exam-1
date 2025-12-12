import math

try:
    so_luong_thanh_pho = int(input())
except ValueError:
    so_luong_thanh_pho = 0

try:
    thoi_gian_ha_noi_str = input()
    gio_hn, phut_hn = map(int, thoi_gian_ha_noi_str.split(':'))
except (ValueError, EOFError):
    gio_hn, phut_hn = 0, 0

ket_qua_list = []

for _ in range(so_luong_thanh_pho):
    try:
        dong_input = input().split()
        
        ten_thanh_pho = dong_input[0]
        do_lech_gio = int(dong_input[1])
        
        # Tinh toan gio moi, su dung modulo 24
        gio_moi = (gio_hn + do_lech_gio) % 24
        
        # Phut giu nguyen
        phut_moi = phut_hn
        
        # Dinh dang output voi 2 chu so cho gio va phut
        output_str = f"{ten_thanh_pho} {gio_moi:02d}:{phut_moi:02d}"
        ket_qua_list.append(output_str)
        
    except (ValueError, EOFError, IndexError):
        pass

for ket_qua in ket_qua_list:
    print(ket_qua)