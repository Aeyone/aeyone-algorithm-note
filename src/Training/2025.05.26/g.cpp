#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	vector<string> g(3);
	for(int i = 0; i < 3; i ++)
		cin >> g[i];
	vector<string> g1(3);
	for(int i = 0; i < 3; i ++)
		g1[2 - i] = g[i], reverse(g1[2 - i].begin(), g1[2 - i].end());

	bool ok = true;
	for(int i = 0; i < 3; i ++)
		for(int j = 0; j < 3; j ++)
			ok &= (g[i][j] == g1[i][j]);
	
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}