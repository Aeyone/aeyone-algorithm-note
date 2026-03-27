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
	vector<int> l(n), c(n);
	for (int i = 0; i < n; i ++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}
	map<int, i64> dp; // dp[i][j]代表前i个物品中，gcd为j的最小费用
	dp[0] = 0;

	for (int i = 0; i < n; i ++) {
		map<int, i64> cur;
		for (auto [lastgcd, cost] : dp) {
			int g =__gcd(lastgcd, l[i]);
			cur[g] = min((cur.find(g) == cur.end() ? INF : cur[g]), cost + c[i]);
			cur[lastgcd] = min((cur.find(lastgcd) == cur.end() ? INF : cur[lastgcd]), cost);
		}
		dp = cur;
	}
	cout << (dp.find(1) != dp.end() ? dp[1] : -1) << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}