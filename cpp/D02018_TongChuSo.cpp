#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int A, B, K;
bool timThay;
int mangChuSo[101];

void timGiaiPhap(int viTri, int tongHienTai, int tongBPHienTai, int chuSoBatDau) {
    if (timThay) {
        return;
    }

    if (viTri == K) {
        if (tongHienTai == A && tongBPHienTai == B) {
            timThay = true;
            for (int i = 0; i < K; i++) {
                cout << mangChuSo[i];
            }
            cout << "\n";
        }
        return;
    }

    for (int d = chuSoBatDau; d <= 9; d++) {
        int tongMoi = tongHienTai + d;
        int tongBPMoi = tongBPHienTai + d * d;

        if (tongMoi > A || tongBPMoi > B) {
            break;
        }

        int soLuongConLai = K - viTri - 1;
        if (tongMoi + soLuongConLai * d > A || tongMoi + soLuongConLai * 9 < A) {
            continue;
        }
        if (tongBPMoi + soLuongConLai * d * d > B || tongBPMoi + soLuongConLai * 81 < B) {
            continue;
        }

        mangChuSo[viTri] = d;
        timGiaiPhap(viTri + 1, tongMoi, tongBPMoi, d);

        if (timThay) {
            return;
        }
    }
}

void giaiQuyet() {
    cin >> A >> B;
    timThay = false;

    for (K = 1; K <= 100; K++) {
        for (int d1 = 1; d1 <= 9; d1++) {
            int tongHienTai = d1;
            int tongBPHienTai = d1 * d1;

            if (tongHienTai > A || tongBPHienTai > B) {
                break;
            }

            mangChuSo[0] = d1;

            if (K == 1) {
                if (tongHienTai == A && tongBPHienTai == B) {
                    timThay = true;
                    cout << d1 << "\n";
                }
            } else {
                int soLuongConLai = K - 1;
                if (tongHienTai + soLuongConLai * d1 > A || tongHienTai + soLuongConLai * 9 < A) {
                    continue;
                }
                if (tongBPHienTai + soLuongConLai * d1 * d1 > B || tongBPHienTai + soLuongConLai * 81 < B) {
                    continue;
                }

                timGiaiPhap(1, tongHienTai, tongBPHienTai, d1);
            }

            if (timThay) {
                break;
            }
        }

        if (timThay) {
            break;
        }
    }

    if (!timThay) {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
