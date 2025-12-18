#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;

	map<int, bool> mp;
	for(int i = 1; (1 << i) < 1e9; i ++){
		mp[(1 << i) + 1] = true;
	}
	vector<int> a(n + 1), c1(n + 1), c2(n + 1), lg(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		lg[i] = lg[i - 1] + (int)log2(a[i]);
		c1[i] = c1[i - 1] + (mp[a[i]]);//前缀中2^n+1的数量
		c2[i] = c2[i - 1] + (mp[a[i] + 1]);//前缀中2^n的数量
	}

	while(q --){
		int l, r;
		cin >> l >> r;
		int cnt1 = c1[r] - c1[l - 1], cnt2 = c2[r] - c2[l - 1];
		int cnt3 = r - l + 1 - cnt1 - cnt2;//必定产生贡献的数量
		cout << lg[r] - lg[l - 1] + cnt3 + cnt1 / 2 << '\n';
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