#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int idx = n;
	vector<int> suf(n + 1), pre(n + 1);
	suf[n] = n;
	for(int i = n - 1; i >= 0; i --){
		suf[i] = (s[i] == '1' ? i : suf[i + 1]);
	}
	pre[0] = (s[0] == '0' ? 0 : -1);
	for(int i = 1; i < n; i ++){
		pre[i] = (s[i] == '0' ? i : pre[i - 1]);
	}
	map<pair<int ,int>, bool> mp;
	while(m --){
		int l, r;
		cin >> l >> r;
		l --, r --;
		l = min(r, suf[l]), r = max(l, pre[r]);
		if(l == r)
			l = 0, r = 0;
		mp[{l, r}] = true;
	}
	cout << mp.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}