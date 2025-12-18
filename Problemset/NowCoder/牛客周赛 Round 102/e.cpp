#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int num[650], dp[N];//total = 632	

void solve() {
	int k;
	cin >> k;
	cout << dp[k] - 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int s = 0, n = 632;
	for(int i = 1; i <= n; i ++)
		s += i, num[i] = s;

	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = num[i]; j <= N - 10; j ++){
			dp[j] = min(dp[j], dp[j - num[i]] + i + 1);
		}
	}
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}