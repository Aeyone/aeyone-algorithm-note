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
	const int N = 20;
	int n;
	cin >> n;

	int st = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		st |= (1 << x);
	}

	vector<vector<int>> mask(N);
	for (int i = st; i > 0; i = (i - 1) & st) { // 枚举子集
		mask[__builtin_popcount(i)].push_back(i);
	}

	vector<double> dp(1 << N, 1e9);
	dp[0] = 0;
	for (int i = 1; i < N; i ++) {
		for (auto cur : mask[i]) {
			for (int j = 0; j + 2 < N; j ++) {
				double res = 1, cnt = 0;
				for (int k = j; k - j < 3; k ++) {
					if (cur >> k & 1) {
						res += dp[cur ^ (1 << k)] / 3;
					} else {
						cnt ++;
					}
				}
				if (cnt != 3) {
					dp[cur] = min(dp[cur], res * 3 / (3 - cnt));
				}
			}
		}
	}
	cout << dp[st] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}