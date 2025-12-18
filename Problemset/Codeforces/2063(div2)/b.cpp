#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	l --, r --;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector<int> b, suf, pre;
	for(int i = 0; i < n; i ++){
		if(i >= l && i <= r)
			b.push_back(a[i]);
		if(i < l)
			pre.push_back(a[i]);
		if(i > r)
			suf.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	sort(pre.begin(), pre.end());
	sort(suf.begin(), suf.end());
	vector<int> tmp = b;
	int pos = 0;
	i64 s1 = 0, s2 = 0;
	while(pos < suf.size() && tmp.size() && suf[pos] < tmp.back())
		s1 += suf[pos ++], tmp.pop_back();
	for(auto e : tmp)
		s1 += e;

	tmp = b, pos = 0;
	while(pos < pre.size() && tmp.size() && pre[pos] < tmp.back())
		s2 += pre[pos ++], tmp.pop_back();

	for(auto e : tmp)
		s2 += e;
	cout << min(s1, s2) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}