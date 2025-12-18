#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


void solve() {
	int l, r;
	cin >> l >> r;
	int mx = r;
	vector<int> a(r + 1);
	while(mx > 0){
		int d = (1 << ((int)log2(mx) + 1)) - 1;
		for(int i = mx; i >= d - mx; i --){
			a[i] = d - i;
		}
		mx = d - mx - 1;
	}
	i64 sum = 0;
	for(int i = 0; i <= r; i ++){
		sum += (a[i] | i);
	}
	cout << sum << '\n';
	for(auto e : a){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// cout << log2(5) << '\n';
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}