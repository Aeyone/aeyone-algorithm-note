#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

/*
*	dp[i][j]为在前i个位置放完1~i所有数，末尾放的是第j大的数的方案数
*
*	注意：只有当前>的转移时，原来末尾状态是当前枚举的num也无所谓，<是不行的
*	比方说以下就是一个有效转移，对于当前末尾为2的状态，可以由上一个末尾为2的状态转移而来
*			 3 1 4 2 -> 4 1 5 3 2   (3>2)
*	意思就是不要管当前i=5,j=2这个状态的前面1~4具体是什么数字，只要可以保证大小关系就可以了
*	而一个排列的子集的一个大小关系也就相当于是一个排列，也就是说{3 1 4 2}等价于{4 1 5 3}
*/

const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = " " + s;
	vector<vector<int>> dp(2);
	dp[0].assign(n + 1, 0);
	dp[0][1] = 1;
	for (int i = 1; i < n; i ++) { 
		vector<int> sum(n + 1);
		for (int j = 1; j <= n; j ++) {
			sum[j] = (sum[j - 1] + dp[~i & 1][j]) % MOD;
		}
		dp[i & 1].assign(n + 1, 0);
		for (int num = 1; num <= i + 1; num ++) {
			if (s[i] == '>') {
				dp[i & 1][num] = (MOD + sum[i] - sum[num - 1]) % MOD;
			} else {
				dp[i & 1][num] = sum[num - 1];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans = (ans + dp[(n - 1) & 1][i]) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}