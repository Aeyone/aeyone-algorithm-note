#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n = 8;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(g[i][j] == '*'){
				cout << (char)('a' + j);
				cout << n - i << '\n';
			}
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}