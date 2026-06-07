/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/2413
 */

 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

int t, n;
const int MAX_N = 1e6;
vector<ll> join(MAX_N+1, 0); // AA
vector<ll> separate(MAX_N+1, 0); // A|A

void precompute() {
    join[1] = 1;
    separate[1] = 1;

    for (int h = 2; h <= MAX_N; h++) {
        join[h] = (2*join[h-1] + separate[h-1]) % MOD;
        separate[h] = (join[h-1] + 4*separate[h-1]) % MOD;
    }
}

ll solve() {
    return (join[n] + separate[n]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    precompute();

    while (t-- > 0) {
        cin >> n;
        ll result = solve();
        cout << result << endl;
    }
 
    return 0;
}