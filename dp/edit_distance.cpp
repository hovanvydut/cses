/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1639
 */

 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

string s1, s2;

ll solve() {
    int n = s1.size(), m = s2.size();

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1+ min({
                    dp[i][j-1], // add
                    dp[i-1][j], // remove
                    dp[i-1][j-1]// replace
                });
            }
        }
    }

    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    cout << solve() << endl;
 
    return 0;
}