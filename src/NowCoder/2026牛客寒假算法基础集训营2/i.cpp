#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i ++) {
		cin >> g[i];
		c0 += count(g[i].begin(), g[i].end(), '0');
		c1 += count(g[i].begin(), g[i].end(), '1');
	}
	if (c0 == 1) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cout << (g[i][j] != '0' ? 'Y' : 'N');
			}
			cout << '\n';
		}
	} else if (c1 == 1) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cout << (g[i][j] != '1' ? 'Y' : 'N');
			}
			cout << '\n';
		}
	} else {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cout << 'Y';
			}
			cout << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}