#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int l, r;
	cin >> l >> r;
	int n = r - l + 1;
	vector<int> a(n), bit(21), normal(21);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		for(int j = 0; a[i] >> j > 0; j ++){
			bit[j] += (a[i] >> j & 1);
		}
	}
	for(int i = l; i <= r; i ++){
		for(int j = 0; i >> j > 0; j ++){
			normal[j] += (i >> j & 1);
		}
	}
	int x = 0;
	for(int i = 20; i >= 0; i --){
		bool ok = true;
		for(int j = 0; j < n; j ++){
			ok &= ((a[j] >> i & 1) == ((j + l) >> i & 1));
		}
		x += (normal[i] != bit[i]) * (1 << i);
	}
	cout << x << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}