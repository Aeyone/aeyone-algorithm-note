#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define int long long

const int MOD = 998244353;
const int N = 1e5 + 10;

bool isLow(char x) {
	return x >= 'a' && x <= 'z';
}

bool isUp(char x) {
	return x >= 'A' && x <= 'Z';
}

bool isNum(char x) {
	return x >= '0' && x <= '9';
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	const int m = 150;
	int dp[1 << 3][2][m] = {};
	for (int mask = 1; mask < 1 << 3; mask ++) {
		dp[mask][1][1] = 1;
		for (int i = 0; i < n; i ++) {
			vector<int> pre(m);
			for (int j = 1; j < m; j ++) {
				pre[j] = (pre[j - 1] + dp[mask][i - 1 & 1][j]) % MOD;
				dp[mask][i & 1][j] = 0;
			}

			if (s[i] == '?') {
				for (int j = 1; j < m; j ++) {
					if ((mask >> 0 & 1) && isLow(j)) {
						dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
					}
					if ((mask >> 1 & 1) && isUp(j)) {
						dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
					}
					if ((mask >> 2 & 1) && isNum(j)) {
						dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
					}
				}
			} else if (isLow(s[i])) {
				char j = s[i];
				if (mask >> 0 & 1) {
					dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
				}
				j -= ('a' - 'A');
				if (mask >> 1 & 1) {
					dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
				}
			} else {
				char j = s[i];
				if ((mask >> 1 & 1) && isUp(j)) {
					dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
				}
				if ((mask >> 2 & 1) && isNum(j)) {
					dp[mask][i & 1][j] = (dp[mask][i & 1][j] + pre[j - 1] + (pre[m - 1] - pre[j] + MOD) % MOD) % MOD;
				}
			}
		}
	}

	int ans=0;
	for(int i=0;i<(1<<3);i++){
		int op=1,sum=0;
		if(__builtin_popcount(i)%2==0) op=-1;
		for(int j=0;j<m;j++) sum= (sum + dp[i][n-1&1][j]) % MOD;
		ans = (ans + op*sum + MOD) % MOD;
	}
	cout<<ans<<endl;
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