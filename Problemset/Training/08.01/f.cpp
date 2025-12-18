#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
i64 f[65][65][30], res[65][65];//双重背包，预处理出在前k个数中选，x向右移i位和y向右移j位的最小代价

void solve() {
	i64 x, y;
	cin >> x >> y;
	i64 ans = 1e17;
	for(int i = 0; i <= 60; i ++){
		for(int j = 0; j <= 60; j ++){
			if((x >> i) != (y >> j))
				continue;
			ans = min(ans, res[i][j]);
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	memset(f, 0x3f, sizeof f);
	memset(res, 0x3f, sizeof res);
	for(int i = 0; i < 30; i ++)
		f[0][0][i] = 0;

	for(int k = 1; k < 30; k ++){
		for(int i = 0; i <= 60; i ++){
			for(int j = 0; j <= 60; j ++){
				f[i][j][k] = min(f[i][j][k], f[i][j][k - 1]);
				if(i >= k)
					f[i][j][k] = min(f[i][j][k], f[i - k][j][k - 1] + (1ll << k));
				if(j >= k)
					f[i][j][k] = min(f[i][j][k], f[i][j - k][k - 1] + (1ll << k));
				res[i][j] = min(res[i][j], f[i][j][k]);
			}
		}
	}
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}