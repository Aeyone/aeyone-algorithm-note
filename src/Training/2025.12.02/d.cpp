#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	vector<vector<int>> dp(n, vector<int>(1 << m, INF));
	for(int mask = 0; mask < 1 << m; mask ++){
		bool ok = true;
		for(int j = 0; j < m; j ++){
			if(mask >> j & 1){
				ok &= (g[0][j] == '#');//保证操作的位置一定是黑色
			}
		}
		if(ok){
			dp[0][mask] = __builtin_popcount(mask);
		}
	}
	for(int i = 1; i < n; i ++){
		for(int mask = 0; mask < 1 << m; mask ++){//0为不操作，1为操作
			bool ok = true;
			for(int j = 0; j < m; j ++){
				if(mask >> j & 1){
					ok &= (g[i][j] == '#');//保证操作的位置一定是黑色
				}
			}
			if(!ok){
				continue;
			}
			for(int la = 0; la < 1 << m; la ++){//枚举上一层的操作
				bool ok1 = true;
				for(int j = 0; j < m; j ++){
					if(la >> j & 1){
						ok1 &= (g[i - 1][j] == '#');//保证操作的位置一定是黑色
					}
				}
				if(!ok1){
					continue;
				}
				for(int j = 1; j < m; j ++){
					int cnt = 0;
					cnt += (g[i - 1][j - 1] == '#') ^ (la >> (j - 1) & 1);
					cnt += (g[i - 1][j] == '#') ^ (la >> j & 1);
					cnt += (g[i][j - 1] == '#') ^ (mask >> (j - 1) & 1);
					cnt += (g[i][j] == '#') ^ (mask >> j & 1);
					ok1 &= (cnt < 4);
				}
				if(ok1){
					dp[i][mask] = min(dp[i][mask], dp[i - 1][la] + __builtin_popcount(mask));
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < 1 << m; i ++){
		ans = min(ans, dp[n - 1][i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}