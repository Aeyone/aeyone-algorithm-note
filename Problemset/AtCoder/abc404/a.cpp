#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	bool vis[26] = {};
	for(auto e : s)
		vis[e - 'a'] = true;

	for(int i = 0; i < 26; i ++)
		if(!vis[i]){
			cout << (char)('a' + i) << '\n';
			return;
		}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}