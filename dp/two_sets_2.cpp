/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1093
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define ll long long
const int MOD = 1e9+7;
int n;

/*
void solve() {
    ll sum = n * (n+1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    ll half = sum / 2;
    vector<vector<ll>> dp(n+1, vector<ll>(half+1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // number N must be in another set to avoid overcounting becuase of symetric
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= half; j++) {
            if (j-i >= 0) {
                dp[i][j] = (dp[i-1][j-i] + dp[i-1][j]) % MOD;
            } else {
                 dp[i][j] = dp[i-1][j] % MOD;
            }
        }
    }

    cout << dp[n-1][half] << endl;
}
*/

// Optimize space
void solve() {
    ll sum = n * (n+1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    ll half = sum / 2;
    vector<ll> dp(half+1, 0);
    dp[0] = 1;


    // number N must be in another set to avoid overcounting becuase of symetric
    for (int i = 1; i < n; i++) {
        for (int j = half; j >= i; j--) {
            dp[j] = (dp[j-i] + dp[j]) % MOD;
        }
    }

    cout << dp[half] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    solve();

    return 0;
}