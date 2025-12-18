#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> p = {{1, 1}, {1, 2}};
	int idx = 3, x = n;
	while(x > 2)
		p.push_back({idx, idx}), x --, idx ++;
	
	for(int i = 0; i < n; i ++)
		cout << p[i].first << ' ' << p[i].second << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}