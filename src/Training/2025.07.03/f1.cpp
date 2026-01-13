#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s;
	cin >> t;
	vector<bool> vis(n);
	int to = 0;
	if(k < n)
		vis[to + k] = true;
	for(int i = 0; i <= 2 * n; i ++){
		vis[to] = true;
		if(i & 1)
			to -= k;
		else
			to += k + 1;
		if(to >= n)
			break;
	}
	map<char, int> c1, c2;
	for(int i = 0; i < n; i ++)
		if(vis[i])
			c1[s[i]] ++;
	for(int i = 0; i < n; i ++)
		if(vis[i])
			c2[t[i]] ++;

	bool ok = true;
	for(auto [c, e] : c1)
		ok &= (c2[c] == e);

	for(int i = 0; i < n; i ++)
		if(!vis[i])
			ok &= (s[i] == t[i]);
	// for(int i = 0; i < n; i ++)
	// 	cout << vis[i];
	// cout << '\n';

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