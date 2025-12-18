#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i < n; i ++)
		cin >> g[i];

	vector<int> u(n);

	for(int i = 1; i < n; i ++){
		for(int j = 0; j < i; j ++){
			if(g[i][j] == '1')
				u[i] = max(u[i], u[j] + 1);
			if(g[i][j] == '0')
				u[j] ++;
		}
	}
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i ++)
		v[i] = {u[i], i + 1};

	sort(v.begin(), v.end());
	for(auto [_, e] : v)
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