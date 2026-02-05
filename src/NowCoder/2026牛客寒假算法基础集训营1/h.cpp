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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<i64> dp(n);
	int cur = 0;
	for (int l = 0, r = 0; l < n; l ++) {
		while (r < n && cur + a[r] == (cur | a[r])) {
			cur |= a[r];
			dp[r] = (l == 0 ? 1 : dp[l - 1]) * (1ll << (r - l)) % MOD;
			r ++;
		}
		cur -= a[l];
	}
	for (int i = 0; i < n; i ++) {
		cout << dp[i] << ' ';
	}
	cout << '\n';
	cout << dp[n - 1] << '\n';
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