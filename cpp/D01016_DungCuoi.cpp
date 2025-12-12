#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    string dongTen;
    getline(cin, dongTen);

    string tenCoDinh;
    cin >> tenCoDinh;

    vector<string> tenDeHoanVi;
    stringstream ss(dongTen);
    string ten;

    while (ss >> ten) {
        if (ten != tenCoDinh) {
            tenDeHoanVi.push_back(ten);
        }
    }

    sort(tenDeHoanVi.begin(), tenDeHoanVi.end());

    do {
        for (const string& t : tenDeHoanVi) {
            cout << t << " ";
        }
        cout << tenCoDinh << endl;
    } while (next_permutation(tenDeHoanVi.begin(), tenDeHoanVi.end()));

    return 0;
}
