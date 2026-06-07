/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1638
 */

 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

int n, m;
vector<int> x;

ll solve() {
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int v = 1; v <= m; v++) {
                dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;
            }
        } else {
            int v = x[i];
            dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;
        }
    }

    ll res = 0;
    for (int v = 1; v <= m; v++) {
        res = (res + dp[n-1][v]) % MOD;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll result = solve();

    cout << result << endl;
 
    return 0;
}