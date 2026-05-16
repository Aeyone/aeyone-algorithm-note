#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;
const int P = 31;

void solve() {
	int n, m;
	cin >> n >> m;
	vector a(n + 1, vector<int>(n + 1));
	vector b(m + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> b[i][j];
		}
	}
	vector sum(m + 1, vector(m + 1, vector<int>(P)));
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			for (int k = 0; k < P; k ++) {
				sum[i][j][k] = (b[i][j] >> k & 1) + sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
			}
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			int lo[2] = {i - (min(i + m - 1, n) - m + 1) + 1, j - (min(j + m - 1, n) - m + 1) + 1};
			int hi[2] = {i - max(i - m + 1, 1) + 1, j - max(j - m + 1, 1) + 1};
			for (int k = 0; k < P; k ++) {
				int cnt[2] = {};
				cnt[1] = sum[hi[0]][hi[1]][k] - sum[lo[0] - 1][hi[1]][k] - sum[hi[0]][lo[1] - 1][k] + sum[lo[0] - 1][lo[1] - 1][k];
				cnt[0] = (hi[0] - lo[0] + 1) * (hi[1] - lo[1] + 1) - cnt[1];
				ans = (ans + (1ll << k) * cnt[!(a[i][j] >> k & 1)]) % MOD;
			}
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