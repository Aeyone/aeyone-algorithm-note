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
*	枚举所有可能被加入的num，如果可以被加入，那么在原序列中一定存在某些数的gcd为num
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), vis(1e6 + 1);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		vis[a[i]] = true;
	}
	int ans = 0;
	for (int i = 1; i <= 1e6; i ++) {
		int g = 0;
		for (int j = 1; i * j <= 1e6; j ++) {
			if (vis[i * j]) {
				g = __gcd(g, i * j);
			}
		}
		if (g == i) {
			ans += !vis[i];
		}
	}
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