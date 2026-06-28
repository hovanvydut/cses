/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1745
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> X;
int MAX_SUM = 1e5;

void solve() {
    vector<vector<bool>> dp(MAX_SUM + 1, vector<bool>(n+1, false));
    for (int j = 0; j <= n; j++) {
        dp[0][j] = true;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= MAX_SUM; i++) {
            if (i - X[j] < 0) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i-X[j]][j-1] || dp[i][j-1];
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= MAX_SUM; i++) {
        if (dp[i][n]) {
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    X.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }

    solve();

    return 0;
}