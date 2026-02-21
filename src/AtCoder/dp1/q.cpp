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
	vector<int> h(n), a(n);
	for (int i = 0; i < n; i ++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
/*
*	d[len]存的整个长度为len的子序列的末尾高度的贡献的集合，高度从大到小
*	d[len].back()表示长度为len最大贡献，用单调栈维护
*	dp[len]表示当前长度为len的子序列结尾的高度的最小值
*/
	vector<vector<i64>> val;
	vector<vector<int>> d;
	vector<int> dp;

	val.push_back({0});
	d.push_back({0});
	dp.push_back(0);

	for (int i = 0; i < n; i ++) {
		// cerr << "siz = " << val.size() << '\n';
		// cerr << "siz = " << d.size() << '\n';
		// cerr << "siz = " << dp.size() << '\n';
		if (h[i] > dp.back()) {
			int idx2 = upper_bound(d.back().begin(), d.back().end(), h[i], greater<int>{}) - d.back().begin();
			val.push_back({val[val.size() - 1][idx2] + a[i]});
			d.push_back({h[i]});
			dp.push_back(h[i]);
		} else {
			int idx = upper_bound(dp.begin(), dp.end(), h[i]) - dp.begin();
			int idx2 = upper_bound(d[idx - 1].begin(), d[idx - 1].end(), h[i], greater<int>{}) - d[idx - 1].begin();
			// cerr << "h[i] = " << h[i] << '\n';
			// cerr << "idx = " << idx << '\n';
			// cerr << "idx2 = " << idx2 << '\n';
			// cerr << "val = " << val[idx - 1][idx2] << '\n';
			// cerr << '\n';

			while (val[idx].size() && val[idx].back() <= val[idx - 1][idx2] + a[i]) {
				val[idx].pop_back();
				d[idx].pop_back();
			}
			val[idx].push_back(val[idx - 1][idx2] + a[i]);
			d[idx].push_back(h[i]);
			dp[idx] = h[i];
		}
	}
	i64 ans = 0;
	for (auto v : val) {
		for (auto e : v) {
			// cout << e << ' ';
			ans = max(ans, e);
		}
		// cout << '\n';
	}
	// for (auto v : d) {
	// 	for (auto e : v) {
	// 		cout << e << ' ';
	// 	}
	// 	cout << '\n';
	// }
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