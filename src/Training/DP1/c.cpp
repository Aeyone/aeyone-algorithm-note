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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> cnt(11, vector<int>(11));
	for (int i = 0; i < n; i ++) {
		int w, v;
		cin >> w >> v;
		cnt[w][v] ++;
	}

	vector<vector<int>> dp(2, vector<int>(m + 1));
	int cur = 0;

	for (int w = 0; w <= 10; w ++) {
		for (int v = 0; v <= 10; v ++) {
			int c = cnt[w][v];
			dp[cur] = dp[!cur];
			for (int i = 0; i < w; i ++) {
				deque<int> q;
				for (int j = i; j <= m; j += w) {
					if (q.size() && q.front() < j - c * w) {
						q.pop_front();
					}

					if (q.size()) {
						dp[cur][j] = max(dp[!cur][j], dp[!cur][q.front()] + (j - q.front()) / w * v);
					}

					while (q.size() && dp[!cur][j] >= dp[!cur][q.back()] + (j - q.back()) / w * v) {
						q.pop_back();
					}

					q.push_back(j);
				}
			}
			cur = !cur;
		}
	}
	cout << dp[!cur][m] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}