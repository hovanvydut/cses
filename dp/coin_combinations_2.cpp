/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1636
 */

 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, x;
vector<int> c;
vector<ll> dp;
const ll MOD = 1e9+7;

ll solve(int x) {
    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (int ci : c) {
        for (int i = ci; i <= x; i++) {
            dp[i] = (dp[i] + dp[i-ci]) % MOD;
        }
    }

    return dp[x];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
    c.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }


    ll result = solve(x);

    cout << result;
 
    return 0;
}