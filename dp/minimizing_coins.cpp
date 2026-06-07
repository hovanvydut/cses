/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1634
 */
 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, x;
vector<int> c;
vector<ll> memo;
const ll INF = 1e9;

ll solve(int x) {
    if (x == 0) return 0;
    if (x < 0) return INF;

    if (memo[x] != -1) {
        return memo[x];
    }

    ll res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, 1 + solve(x - c[i]));
    }

    return memo[x] = res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
    c.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    memo.resize(x + 1, -1);

    ll result = solve(x);

    if (result == INF) {
        cout << "-1";
    } else {
        cout << result;
    }
 
    return 0;
}