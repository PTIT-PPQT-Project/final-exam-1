#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <set>       

using namespace std;

int main() {
    int N;
    cin >> N;


    vector<string> final_results;

    for (int L = 1; L <= N; ++L) {
        

        if (L < 3) {
            continue;
        }


        set<string> strings_for_length_L;


        for (int nA = 1; nA <= L; ++nA) {
            
            
            for (int nB = nA; nB <= L; ++nB) {
                

                int nC = L - nA - nB;

               
                if (nC >= nB) {
                    
                    string base_string = "";
                    for (int i = 0; i < nA; ++i) base_string += 'A';
                    for (int i = 0; i < nB; ++i) base_string += 'B';
                    for (int i = 0; i < nC; ++i) base_string += 'C';

                    
                    do {
                        strings_for_length_L.insert(base_string);
                    } while (next_permutation(base_string.begin(), base_string.end()));
                }
            }
        }

       
        for (const string& s : strings_for_length_L) {
            final_results.push_back(s);
        }
    }

    for (const string& s : final_results) {
        cout << s << endl;
    }

    return 0;
}
