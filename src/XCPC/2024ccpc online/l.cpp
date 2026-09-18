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
	for (int i = 0; i < n; i ++) {
		cin >> g[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < m - 1; j ++) {
			string s;
			s += g[i][j];
			s += g[i][j + 1];
			s += g[i + 1][j];
			s += g[i + 1][j + 1];
			ans += (s == "ccpc");
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}