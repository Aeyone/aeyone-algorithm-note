#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//dp好题
	int x, n, m;
	cin >> x >> n >> m;
	n = min(30, n), m = min(30, m);
	int N = n + m;
	int f[100][40][40] = {};
	f[0][0][0] = x;
	for(int i = 0; i < N; i ++){
		for(int j = 0; j <= i; j ++){
			int k = i - j;
			f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k] / 2);
			f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], (f[i][j][k] + 1) / 2);
		}
	}
	i64 g[100][40][40] = {};
	memset(g, 0x3f, sizeof g);
	g[0][0][0] = x;
	for(int i = 0; i < N; i ++){
		for(int j = 0; j <= i; j ++){
			int k = i - j;
			g[i + 1][j + 1][k] = min(g[i + 1][j + 1][k], g[i][j][k] / 2);
			g[i + 1][j][k + 1] = min(g[i + 1][j][k + 1], (g[i][j][k] + 1) / 2);
		}
	}
	cout << g[N][n][m] << ' ' << f[N][n][m] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}