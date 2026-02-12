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
	int n;
	cin >> n;
	using T = array<int, 2>;
	vector<T> alls(n + 2);
	cin >> alls[0][0] >> alls[0][1] >> alls[n + 1][0] >> alls[n + 1][0];
	for (int i = 1; i <= n; i ++) {
		cin >> alls[i][0];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> alls[i][1];
	}
	sort(alls.begin(), alls.end());

	vector<vector<T>> fl;
	for (int l = 0, r = 0; l < n + 2; l = r) {
		vector<T> v = {{-1, -1}};
		while (r < n + 2 && alls[r][0] == alls[l][0]) {
			v.push_back(alls[r ++]);
		}
		fl.push_back(v);
	}

	int m = fl.size();
	vector<int> mx(m, -INF), mn(m, INF);
	for (int i = 1; i < m; i ++) {
		for (auto [x, y] : fl[i]) {
			mx[i] = max(mx[i], y);
			mn[i] = min(mn[i], y);
		}
	}
	vector<vector<i64>> pre(m), suf(m), dp(m), a(m);
	for (int i = 0; i < m; i ++) {
		int siz = fl[i].size();
		pre[i].assign(siz + 1, INFLL);
		suf[i].assign(siz + 1, INFLL);
		a[i].assign(siz + 1, INFLL);
		dp[i].assign(siz + 1, INFLL);
	}
	a[0][1] = 0;
	for (int i = 0; i <= m - 2; i ++) {
		int siz = fl[i].size() - 1;
		if (i > 0) {
			for (int j = 1; j <= siz; j ++) {
				auto [x, y] = fl[i][j];
				int lax = fl[i - 1][1][0];
				int Mx = max(y, mx[i + 1]);
				int Mn = min(y, mn[i + 1]);
				int idx = lower_bound(fl[i - 1].begin() + 1, fl[i - 1].end(), T{lax, y}) - fl[i - 1].begin();
				dp[i][j] = lax - x + min(pre[i - 1][idx - 1] - y, suf[i - 1][idx] + y) + 2 * (Mx - Mn);
			}
		} else {
			auto [x, y] = fl[0][1];
			int Mx = max(y, mx[i + 1]);
			int Mn = min(y, mn[i + 1]);
			dp[0][1] = 2 * (Mx - Mn);
		}
		for (int j = 1; j <= siz; j ++) {
			pre[i][j] = min(pre[i][j - 1], dp[i][j] + fl[i][j][1]);
		}
		for (int j = siz; j >= 1; j --) {
			suf[i][j] = min(suf[i][j + 1], dp[i][j] - fl[i][j][1]);
		}
	}
	int lax = fl[m - 2][1][0];
	auto [x, y] = fl[m - 1][1];
	int idx = lower_bound(fl[m - 2].begin() + 1, fl[m - 2].end(), T{lax, y}) - fl[m - 2].begin();
	cout << lax - x + min(pre[m - 2][idx - 1] - y, suf[m - 2][idx] + y) << '\n';
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