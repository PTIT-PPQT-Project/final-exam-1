#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int N, M;
int A[501][501];
int dist[501][501];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct State {
    int cost;
    int r;
    int c;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void giaiQuyet() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            dist[i][j] = INF;
        }
    }

    priority_queue<State, vector<State>, greater<State>> pq;

    dist[0][0] = A[0][0];
    pq.push({dist[0][0], 0, 0});

    while (!pq.empty()) {
        State top = pq.top();
        pq.pop();

        int d = top.cost;
        int r = top.r;
        int c = top.c;

        if (d > dist[r][c]) {
            continue;
        }

        if (r == N - 1 && c == M - 1) {
            cout << d << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc)) {
                int newCost = d + A[nr][nc];
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
