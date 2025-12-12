import sys
import bisect

def ham_chinh():
    try:
        q_dong = sys.stdin.readline()
        if not q_dong:
            return
        q = int(q_dong.strip())
        
        id_den_ten = {}
        ten_den_id = {}
        danh_sach_ten_da_sap_xep = []

        for _ in range(q):
            dong_truy_van = sys.stdin.readline().strip()
            if not dong_truy_van:
                continue
            
            cac_phan = dong_truy_van.split()
            if not cac_phan:
                continue
                
            lenh = cac_phan[0]
            
            if lenh == "REGISTER":
                try:
                    id_nguoi_choi = int(cac_phan[1])
                    ten = cac_phan[2]
                    
                    if id_nguoi_choi in id_den_ten:
                        print("ERROR_DUPLICATE_ID")
                    elif ten in ten_den_id:
                        print("ERROR_DUPLICATE_NAME")
                    else:
                        id_den_ten[id_nguoi_choi] = ten
                        ten_den_id[ten] = id_nguoi_choi
                        bisect.insort(danh_sach_ten_da_sap_xep, ten)
                except (IndexError, ValueError):
                    pass

            elif lenh == "RENAME":
                try:
                    id_nguoi_choi = int(cac_phan[1])
                    ten_moi = cac_phan[2]
                    
                    if id_nguoi_choi not in id_den_ten:
                        print("ERROR_ID_NOT_FOUND")
                    else:
                        ten_cu = id_den_ten[id_nguoi_choi]
                        if ten_moi == ten_cu:
                            print("ERROR_SAME_NAME")
                        elif ten_moi in ten_den_id:
                            print("ERROR_DUPLICATE_NAME")
                        else:
                            id_den_ten[id_nguoi_choi] = ten_moi
                            del ten_den_id[ten_cu]
                            ten_den_id[ten_moi] = id_nguoi_choi
                            
                            idx_cu = bisect.bisect_left(danh_sach_ten_da_sap_xep, ten_cu)
                            danh_sach_ten_da_sap_xep.pop(idx_cu)
                            bisect.insort(danh_sach_ten_da_sap_xep, ten_moi)
                except (IndexError, ValueError):
                    pass

            elif lenh == "FIND":
                try:
                    tien_to = cac_phan[1]
                    ket_qua = []
                    
                    idx_bat_dau = bisect.bisect_left(danh_sach_ten_da_sap_xep, tien_to)
                    
                    for i in range(idx_bat_dau, len(danh_sach_ten_da_sap_xep)):
                        ten = danh_sach_ten_da_sap_xep[i]
                        if ten.startswith(tien_to):
                            ket_qua.append(ten)
                        else:
                            break
                    
                    if not ket_qua:
                        print("ERROR_NOT_FOUND")
                    else:
                        print(" ".join(ket_qua))
                        
                except IndexError:
                    print("ERROR_NOT_FOUND")

    except EOFError:
        pass
    except Exception:
        pass

if __name__ == "__main__":
    ham_chinh()