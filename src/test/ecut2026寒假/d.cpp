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
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
		}
	}
	int mx = -INF;
	for (int i = 1; i < n - 1; i ++) {
		for (int j = 1; j < m - 1; j ++) {
			mx = max(mx, a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i + 1][j + 1]);
		}
	}
	cout << mx << '\n';
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