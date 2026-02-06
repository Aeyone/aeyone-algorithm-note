#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/* 
*	设dp[i][j][k] 为寿司数量为1, 2, 3的盘子数量分别为i, j, k个时的期望
*	转移:
*		dp[i][j][k] = 1 + dp[i - 1][j][k] * i / n
*					  + dp[i + 1][j - 1][k] * j / n
*					  + dp[i][j + 1][k - 1] * k / n
*					  + dp[i][j][k] * (1 - (i + j + k) / n)
*
*	对于选寿司数量为0的盘子的情况: 移项处理
*	=> (i + j + k) / n * dp[i][j][k] = 1 + dp[i - 1][j][k] * i / n
*					 				  + dp[i + 1][j - 1][k] * j / n
*					 				  + dp[i][j + 1][k - 1] * k / n
*
*	注意转移顺序，注意到当前k依赖于k-1时的j+1, 当前j依赖于j-1时的i+1
*	因此枚举顺序为 k -> j -> i
*/
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int c[4] = {};
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		c[a[i]] ++;
	}
	vector dp(n + 1, vector(n + 1, vector<double>(n + 1)));
	dp[0][0][0] = 0;
	for (int k = 0; k <= n; k ++) {
		for (int j = 0; j <= n; j ++) {
			for (int i = 0; i <= n; i ++) {
				if (i + j + k == 0) {
					continue;
				}
				dp[i][j][k] = 1;
				if (i - 1 >= 0) {
					dp[i][j][k] += dp[i - 1][j][k] * i / n;
				}
				if (i + 1 <= n && j - 1 >= 0) {
					dp[i][j][k] += dp[i + 1][j - 1][k] * j / n;
				}
				if (j + 1 <= n && k - 1 >= 0) {
					dp[i][j][k] += dp[i][j + 1][k - 1] * k / n;
				}
				dp[i][j][k] /= double(i + j + k) / n;
			}
		}
	}
	cout << dp[c[1]][c[2]][c[3]] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int _ = 1;
	while (_ --) {
		solve();
	}
}