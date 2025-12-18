#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), vis(n);
	for(auto &e : a)
		cin >> e;
	
	int suf = a.back(), mn = inf;
	for(int i = n - 1; i >= 0; i --){
		suf = min(suf, a[i]);
		if(suf != a[i])
			vis[i] = true, mn = min(mn, a[i]);
	}
	for(int i = 0; i < n; i ++){
		if(vis[i] || a[i] > mn + 1)
			a[i] ++;
	}
	sort(a.begin(), a.end());
	for(auto e : a)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}