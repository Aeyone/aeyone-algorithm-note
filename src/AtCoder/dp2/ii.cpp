#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	vector dp(n + 2, vector<int>(n + 2));

	for (int len = 1; len <= n; len ++) {
		for (int l = 1, r = l + len - 1; r <= n; l ++, r ++) {
			for (int i = l; i < r; i ++) {
				cmax(dp[l][r], dp[l][i] + dp[i + 1][r]);
			}
			if (s[l] == 'i' && s[r] == 'i') {
				for (int i = l + 1; i < r; i ++) if (s[i] == 'w') {
					if (dp[l + 1][i - 1] >= i - l - 1 && dp[i + 1][r - 1] >= r - i - 1) {
						dp[l][r] = r - l + 1;
					}
				}
			}
		}
	}
	cout << dp[1][n] / 3 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}