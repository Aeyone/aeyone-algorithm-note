#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	vector<vector<int>> g(32, vector<int>(32, INFLL));
	for (int i = 0; i < 32; i ++) {
		for (int j = 0; j < 32; j ++) {
			if (j == i) {
				g[i][j] = 0;
				continue;
			}
			for (int k = 0; k < n; k ++) {
				if ((a[k] >> i & 1) && (a[k] >> j & 1)) {
					g[i][j] = (1ll << i);
				}
			}
		}
	}
	vector<int> st, ed;
	for (int i = 0; i < 32; i ++) {
		if (a.front() >> i & 1) {
			st.push_back(i);
		}
		if (a.back() >> i & 1) {
			ed.push_back(i);
		}
	}
	for (auto a : st) {
		for (auto b : st) {
			g[a][b] = 0;
		}
	}
	for (int k = 0; k < 32; k ++) {
		for (int i = 0; i < 32; i ++) {
			for (int j = 0; j < 32; j ++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int ans = INFLL;
	for (auto a : st) {
		for (auto b : ed) {
			ans = min(ans, g[a][b] + (1ll << b));
		}
	}
	cout << (ans == INFLL ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}