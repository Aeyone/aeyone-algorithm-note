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
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for (int cur = 0; (1 << cur + 1) - 1 < k; cur ++) {
		a.push_back(1 << cur);
	}
	if (a.size() && k > (a.back() << 1)) {
		a.push_back(k - (a.back() << 1));
	}
	vector<int> dp(n + 1);
	for (int i = 0; i < k; i ++) {
		dp[i] = true;
	}
	for (int i = k + 1; i <= n; i ++) {
		if (!dp[i]) {
			a.push_back(i);
			for (int j = n; j >= i; j --) {
				dp[j] |= dp[j - i];//每次放入一个数时更新状态
			}
			dp[i] = true;
		}
	}
	cout << a.size() << '\n';
	for (auto e : a) {
		cout << e << ' ';
	}
	cout << '\n';
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