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
*	dp[i][j]为价值的前缀和为i，前i个积木中，的最大价值
*/

void solve() {
	int n;
	cin >> n;
	vector<int> w(n), s(n), v(n);
	for (int i = 0; i < n; i ++) {
		cin >> w[i] >> s[i] >> v[i];
	}
	
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}