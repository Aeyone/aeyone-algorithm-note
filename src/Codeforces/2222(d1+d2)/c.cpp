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
	vector<int> a(n + 1), tot;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	tot = a;
	ranges::sort(tot);
	int num = tot[(n + 1) / 2];

	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		 int sum = 0, cnt = 0;
		 for (int j = i; j >= 1; j --) {
		 	if (a[j] > num) {
		 		sum ++;
		 	} else if (a[j] < num) {
		 		sum --;
		 	} else {
		 		cnt ++;
		 	}
		 	if (cnt && cnt - 1 >= abs(sum) && (i - j + 1) & 1) {
		 		dp[i] = max(dp[i], dp[j - 1] + 1);
		 	}
		 }
	}
	cout << dp[n] << '\n';
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