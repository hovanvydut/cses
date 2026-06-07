/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1633
 */
 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n;
vector<ll> memo;
const int MOD = 1e9+7;
 
ll solve(ll n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (memo[n] != -1) {
        return memo[n];
    }

    ll res = 0;

    for (int i = 1; i <= 6; i++) {
        res = (res + solve(n-i)) % MOD;
    }

    return memo[n] = res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    memo.resize(n+1, -1);

    ll result = solve(n);
 
    cout << result;
 
    return 0;
}
