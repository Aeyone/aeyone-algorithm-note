#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int &e : a) {
		cin >> e;
	}
	vector add(n, vector<int>(n));
	for (int i = 0; i < k; i ++) {
		int x, y, c;
		cin >> x >> y >> c;
		x --, y --;
		add[x][y] = c;
	}

	vector<int> mask(1 << n);
	iota(mask.begin(), mask.end(), 0);
	sort(mask.begin(), mask.end(), [](const int &a, const int &b)->bool{
		return __builtin_popcount(a) < __builtin_popcount(b);
	});

	vector dp(1 << n, vector<int>(n)); // 设dp[mask][j]，为当前状态为mask，上一次吃的是第i碗菜时的最大满意度
	int ans = 0;
	for (auto e : mask) {
		int cur = __builtin_popcount(e);
		if (cur == 1) {
			dp[e][__lg(e)] = a[__lg(e)];
		} else {	// 转移的复杂度为n^2
			for (int i = 0; i < n; i ++) if (e >> i & 1) {
				for (int j = 0; j < n; j ++) if ((e >> j & 1) && i != j) {
					dp[e][i] = max(dp[e][i], dp[e ^ (1 << i)][j] + add[j][i] + a[i]);
				}
			}
		}
		if (cur == m) {
			ans = max(ans, *max_element(dp[e].begin(), dp[e].end()));
		}
		if (cur > m) {
			break;
		}
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