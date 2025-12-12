#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K;
vector<int> current_combination;
vector<vector<int>> results;

void print_results_reverse() {
    for (int i = results.size() - 1; i >= 0; --i) {
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << (j == results[i].size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

void generate_combinations(int start_index) {
    if (current_combination.size() == K) {
        results.push_back(current_combination);
        return;
    }

    if (K - current_combination.size() > N - start_index + 1) {
        return;
    }

    for (int i = start_index; i <= N; ++i) {
        current_combination.push_back(i);
        generate_combinations(i + 1);
        current_combination.pop_back();
    }
}

void solve() {
    if (!(cin >> N >> K)) return;

    results.clear();
    current_combination.clear();

    generate_combinations(1);
    print_results_reverse();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        solve();
    }

    return 0;
}