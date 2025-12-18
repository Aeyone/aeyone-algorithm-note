#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<i64, pair<i64, i64>> piii;
#define sd second
#define ft first

void solve() {
	int n, m;
	cin >> n >> m;
	vector<piii> que;
	que.push_back({0, {m, m}});
	for(int i = 0; i < n; i ++){
		i64 t, l, r;
		cin >> t >> l >> r;
		que.push_back({t, {l, r}});
	}
	sort(que.begin(), que.end());
	i64 l = que[0].sd.ft;
	i64 r = que[0].sd.sd;
	bool ok = true;
	for(int i = 1; i <= n; i ++){
		i64 d = que[i].ft - que[i - 1].ft;
		l = max(l - d, que[i].sd.ft);
		r = min(r + d, que[i].sd.sd);
		ok &= (l <= r);//从左到右扫一遍，维护一个可能的区间
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}