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
*	Sg函数，若一个状态存在一个能够到达的状态为必输态，那么此状态一定必胜
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> dp(k + 1);
	int mn = *min_element(a.begin(), a.end());
	for (int i = mn; i <= k; i ++) {
		for (auto e : a) {
			if (i - e >= 0) {
				dp[i] |= !dp[i - e];
			}
		}
	}
	if (dp[k]) {
		cout << "First" << '\n';
	} else {
		cout << "Second" << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}