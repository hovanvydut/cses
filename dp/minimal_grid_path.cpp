/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/3359
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define pii pair<int, int>
#define row first
#define col second

int n;
vector<vector<char>> grid;

string solve() {
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    vector<pii> q;
    q.push_back({0, 0});
    visited[0][0] = true;
    path += grid[0][0];

    // Total steps to reach (n-1, n-1) is 2*n - 1
    for (int step = 1; step < 2 * n; step++) {
        vector<pii> next_candidates;
        char min_char = 'Z' + 1;

        // Step 1: Gather all unique neighbors from the current layer
        for (pii cur : q) {
            // move right
            if (cur.col + 1 < n && !visited[cur.row][cur.col + 1]) {
                min_char = min(min_char, grid[cur.row][cur.col + 1]);
                next_candidates.push_back({cur.row, cur.col + 1});
                // Mark early to avoid duplicate processing
                visited[cur.row][cur.col + 1] = true;
            }

            // move left
            if (cur.row + 1 < n && !visited[cur.row + 1][cur.col]) {
                min_char = min(min_char, grid[cur.row + 1][cur.col]);
                next_candidates.push_back({cur.row + 1, cur.col});
                visited[cur.row + 1][cur.col] = true;
            }
        }

        if (next_candidates.empty()) break;

        // Step 2: Append the absolute best character found for this step
        path += min_char;

        // Step 3: Only keep candidates that match the optimal character
        vector<pii> next_q;
        for (pii candidate : next_candidates) {
            if (grid[candidate.row][candidate.col] == min_char) {
                next_q.push_back(candidate);
            } else {
                // Unmark the losers so they don't break future layers
                visited[candidate.row][candidate.col] = false;
            }
        }

        q = next_q; // Advance to the filtered next layer
    }

    return path;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    grid.resize(n, vector<char>(n, 'A'));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> grid[r][c];
        }
    }

    cout << solve() << endl;

    return 0;
}