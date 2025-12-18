#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i = 10; i + 1ll <= n; i *= 10) {
        ll x = i + 1ll;
        if (n % x == 0) {
            a.push_back(n / x);
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    
    if (a.size() != 0) {
        for (auto e : a)
            cout << e << " ";
        cout << endl;
    }
}
signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}