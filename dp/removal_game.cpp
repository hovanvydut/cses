/**
 * @author hovanvydut
 * @problem https://cses.fi/problemset/task/1097
 * similar: https://leetcode.com/problems/stone-game/?envType=problem-list-v2&envId=game-theory
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define ll long long

int n;
vector<int> A;
vector<ll> prefix;
vector<vector<ll>> memo;
const ll INF = 1e18;

ll play(int l, int r) {
    if (r < l) return 0;

    if (memo[l][r] != -INF) {
        return memo[l][r];
    }

    ll remain_total = prefix[r+1] - prefix[l];

    ll best = -INF;
    {
        // pick left
        ll opponent = play(l+1, r);
        ll you = remain_total - opponent;
        best = max(best, you);
    }
    
    {
        // pick right
        ll opponent = play(l, r-1);
        ll you = remain_total - opponent;
        best = max(best, you);
    }

    return memo[l][r] = best;
}

void solve() {
    // build prefix sum
    prefix.resize(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + A[i-1];
    }

    memo.resize(n+2, vector<ll>(n+2, -INF));

    ll first_player = play(0, n-1);
    cout << first_player << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    A.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}