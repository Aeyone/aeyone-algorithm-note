#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 l, r, G;
	cin >> l >> r >> G;
	l = (l + G - 1) / G, r = r / G;
	i64 len = r - l;
	for(i64 i = len; i >= 0; i --){
		for(i64 L = l; L + i <= r; L ++){
			if(__gcd(L, L + i) == 1){
				cout << L * G << ' ' << (L + i) * G << '\n';
				return;
			}
		}
	}
	cout << -1 << ' ' << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}