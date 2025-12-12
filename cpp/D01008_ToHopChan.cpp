#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> current_combination;

void print_combination(const vector<int>& combination) {
    for (size_t i = 0; i < combination.size(); ++i) {
        cout << combination[i] << (i == combination.size() - 1 ? "" : " ");
    }
    cout << endl;
}

void find_even_sum_combinations(int start_index, int current_sum) {
    if (current_combination.size() == k) {
        if (current_sum % 2 == 0) {
            print_combination(current_combination);
        }
        return;
    }

    if (k - current_combination.size() > n - start_index + 1) {
        return;
    }

    for (int i = start_index; i <= n; ++i) {
        current_combination.push_back(i);
        find_even_sum_combinations(i + 1, current_sum + i);
        current_combination.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k)) {
        return 0;
    }

    find_even_sum_combinations(1, 0);

    return 0;
}