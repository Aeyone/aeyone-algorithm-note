#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n = 6;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int k;
	cin >> k;
	int sum = INF;
	vector<int> ans;
	auto dfs = [&](auto &&self, int idx, int cur, int sum1, int sum2)-> void {
		if (idx > n) {
			if (sum1 >= 19 && sum2 <= k) {
				sum = sum2;
				ans = b;
			}
			return;
		}
		for (int i = cur; i <= 6; i ++) {
			b[idx] = a[i] + 1;
			self(self, idx + 1, i, sum1 + i, sum2 + b[idx]);
		}
	};
	dfs(dfs, 1, 0, 0, 0);
	if (ans.size()) {
		cout << "YES" << '\n';
		ans.back() += k - sum;
		for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
		cout << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}