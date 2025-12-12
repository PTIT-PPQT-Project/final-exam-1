import sys
import json

DAP_AN_DA_XU_LY = {}
TIEN_THUONG_DA_XU_LY = [0] * 16

try:
    with open('datas.json', 'r', encoding='utf-8') as f:
        data = json.load(f)
    
    for bo_cau in data.get('quiz_sets', []):
        id_bo = bo_cau.get('id')
        cau_hoi_list = bo_cau.get('questions', [])
        
        cau_hoi_list.sort(key=lambda x: x.get('id', 0))
        
        dap_an_list = [q.get('correct') for q in cau_hoi_list]
        DAP_AN_DA_XU_LY[id_bo] = dap_an_list

    for giai_thuong in data.get('prizes', []):
        id_cau = giai_thuong.get('question_id')
        so_tien = giai_thuong.get('amount')
        if 1 <= id_cau <= 15:
            TIEN_THUONG_DA_XU_LY[id_cau] = so_tien

except (FileNotFoundError, json.JSONDecodeError):
    sys.exit(1)

try:
    so_test_cases = int(sys.stdin.readline())
except (EOFError, ValueError):
    so_test_cases = 0

for _ in range(so_test_cases):
    try:
        dong_dau_vao = sys.stdin.readline().split()
        if not dong_dau_vao:
            continue
            
        id_bo_cau = int(dong_dau_vao[0])
        danh_sach_tra_loi = dong_dau_vao[1:]
        
        if id_bo_cau not in DAP_AN_DA_XU_LY:
            continue
            
        dap_an_dung_cua_bo = DAP_AN_DA_XU_LY[id_bo_cau]
        
        so_cau_dung_cuoi_cung = 0
        ket_qua_cuoi = 0
        da_dung_choi = False

        for i in range(15):
            so_cau_hien_tai = i + 1
            
            if i >= len(danh_sach_tra_loi):
                ket_qua_cuoi = TIEN_THUONG_DA_XU_LY[so_cau_dung_cuoi_cung]
                da_dung_choi = True
                break

            cau_tra_loi = danh_sach_tra_loi[i]
            
            if cau_tra_loi == "X":
                ket_qua_cuoi = TIEN_THUONG_DA_XU_LY[so_cau_dung_cuoi_cung]
                da_dung_choi = True
                break
            
            if cau_tra_loi == dap_an_dung_cua_bo[i]:
                so_cau_dung_cuoi_cung = so_cau_hien_tai
            else:
                if 1 <= so_cau_hien_tai <= 5:
                    ket_qua_cuoi = TIEN_THUONG_DA_XU_LY[0]
                elif 6 <= so_cau_hien_tai <= 10:
                    ket_qua_cuoi = TIEN_THUONG_DA_XU_LY[5]
                elif 11 <= so_cau_hien_tai <= 15:
                    ket_qua_cuoi = TIEN_THUONG_DA_XU_LY[10]
                da_dung_choi = True
                break

        if da_dung_choi:
            print(ket_qua_cuoi)
        else:
            print(TIEN_THUONG_DA_XU_LY[15])

    except (EOFError, ValueError, KeyError):
        continue