#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l,ll r){
    return uniform_int_distribution<ll>(l,r)(rng);
}

void solve () {
    int n = Rand (1, 16);
    cout << 4 * n << "\n";
    vector<int> a (n);
    for (int i = 0;i < n;i++) {
        a[i] = Rand (1, n);
    }
    vector<int> b;
    for (auto x : a) {
        b.push_back (x);
        b.push_back (x);
        b.push_back (x);
        b.push_back (x);
    }
    int m = Rand (1, (n + 1) / 2);
    for (int i = 0;i < m;i++) {
        int x = Rand (0, 4 * n - 1);
        int y = Rand (0, 4 * n - 1);
        swap (b[x], b[y]);
    }
    for (auto x : b)cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cout << t << "\n";
    while (t --) {
        solve();
    }
}