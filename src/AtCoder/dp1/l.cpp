#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/* 
*	设自己为A，对面是B
*	我需要最大化(A - B)的时候会面临一个(B'- A')最大的一个状态
*	假设这个需要到达的状态为l, r
*	那么需要从 A + a[l] - B 或者 A + a[r] - B 两种状态转移而来
*	推导一下即为 a[l] - (B - A) 和 a[r] - (B - A)
*	所以最大的(A - B)为两者取max
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector dp(n, vector<i64>(n));
	for (int len = 1; len <= n; len ++) {
		for (int l = 0; l + len - 1 < n; l ++) {
			int r = l + len - 1;
			if (len == 1) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
			}
		}
	}

	cout << dp[0][n - 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}