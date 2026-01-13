#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	vector<int> cnt(4 * n);
	int XOR = 0;
	cnt[0] ++;
	i64 ans = (i64)(n + 1) * n / 2;
	for(int i = 0; i < n; i ++){
		XOR ^= a[i];
		for(i64 j = 0; j * j <= 2 * n; j ++){
			i64 num = j * j;
			ans -= cnt[(num ^ XOR)];
		}
		cnt[XOR] ++;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}