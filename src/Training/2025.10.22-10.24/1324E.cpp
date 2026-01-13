#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//dp练手题
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	vector<vector<int>> f(n + 1, vector<int>(h, -INF));
	f[0][0] = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < h; j ++){
			if(f[i][j] == -INF){
				continue;
			}
			int x = (j + a[i + 1]) % h;
			int y = (h + j + a[i + 1] - 1) % h;
			f[i + 1][x] = max(f[i + 1][x], f[i][j] + (x >= l && x <= r));
			f[i + 1][y] = max(f[i + 1][y], f[i][j] + (y >= l && y <= r));
		}
	}
	int ans = 0;
	for(int i = 0; i < h; i ++){
		ans = max(ans, f[n][i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}