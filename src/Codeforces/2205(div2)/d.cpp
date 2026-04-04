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
	vector<int> a(n + 2), la(n + 2), ne(n + 2), stk;
	a[0] = a[n + 1] = INF;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i ++) {
		while (stk.size() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		if (i > 0) {
			la[i] = stk.back();
		}
		stk.push_back(i);
	}
	stk.clear();
	for (int i = n + 1; i >= 1; i --) {
		while (stk.size() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		if (i <= n) {
			ne[i] = stk.back();
		}
		stk.push_back(i);
	}
	vector<int> dp(n + 2, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		dp[i] = min(dp[i], dp[i - 1]);
		if (a[i] == max({a[i - 1], a[i], a[i + 1]})) {
			dp[ne[i]] = min(dp[ne[i]], dp[i] + (ne[i] - i - 1));
			dp[i] = dp[la[i]] + (i - la[i] - 1);
		}
	}

	cout << min(dp[n], dp[n + 1]) << '\n';


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