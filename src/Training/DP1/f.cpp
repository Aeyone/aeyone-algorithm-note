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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> f(m + 1);
	f[0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = m; j >= a[i]; j --) {
			f[j] = (f[j] + f[j - a[i]]) % 10;
		}
	}

	vector<vector<int>> g(n, vector<int>(m + 1));

	for (int i = 0; i < n; i ++) {
		g[i][0] = 1;
		for (int j = 1; j <= m; j ++) {
			if (j - a[i] >= 0) {
				g[i][j] = (10 + f[j] - g[i][j - a[i]]) % 10;
			} else {
				g[i][j] = f[j];
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cout << g[i][j];
		}
		cout << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}