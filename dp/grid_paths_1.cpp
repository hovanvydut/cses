/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1638
 */

 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

int n;
vector<vector<char>> grid;
const char TRAP = '*';

ll solve() {
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][1] = 1;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == TRAP) {
                dp[r+1][c+1] = 0;
            } else {
                dp[r+1][c+1] = (dp[r][c+1] + dp[r+1][c]) % MOD;
            }
        }
    }

    return dp[n][n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    grid.resize(n, vector<char>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> grid[r][c];
        }
    }

    ll result = solve();

    cout << result << endl;
 
    return 0;
}