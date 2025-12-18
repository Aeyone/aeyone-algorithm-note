#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//前缀和+滑动窗口，好题
	int n, m, v;
	cin >> n >> m >> v;
	vector<int> a(n + 2), pre(n + 2), suf(n + 2);
	vector<i64> s(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	i64 cur = 0;
	// cout << "pre: \n";
	for(int i = 1; i <= n; i ++){
		cur += a[i], pre[i] = pre[i - 1], s[i] = s[i - 1] + a[i];
		if(cur >= v)
			cur = 0, pre[i] ++;
		// cout << pre[i] << ' ';
	}
	cur = 0;
	for(int i = n; i >= 1; i --){
		cur += a[i], suf[i] = suf[i + 1];
		if(cur >= v)
			cur = 0, suf[i] ++;
	}
	// cout << "\nsuf: \n";
	// for(int i = 1; i <= n; i ++)
	// 	cout << suf[i] << ' ';
	// cout << '\n';
	if(suf[1] < m && pre[n] < m){
		cout << -1 << '\n';
		return;
	}
	auto query = [&](int l, int r)->i64{
		return (s[r] - s[l - 1]);
	};
	i64 ans = 0;
	int l = 1, r = 0;
	while(r <= n){
		while(l <= r && pre[l - 1] + suf[r + 1] < m)
			l ++;
		if(pre[l] + suf[r] >= m)
			ans = max(ans, query(l, r));
		r ++;
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