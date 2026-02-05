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
	int n, m;
	cin >> n >> m;
	vector<string> s(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}
	set<char> st {'k', 'n', 'a', 'r', 'e'};
	string let = "knare";

	vector<vector<int>> dp(2);
	dp[0].assign(5, -INF);
	dp[0][0] = 0;

	for (int i = 1; i <= n; i ++) {
		dp[i & 1].assign(5, -INF);
		for (int j = 0; j < 5; j ++) {
			dp[i & 1][j] = max(dp[i & 1][j], dp[~i & 1][j]);
			int cur = j, tot = 0, cnt = 0;	

			for (int k = 0; k < m; k ++) {
				if (s[i][k] == let[(cur + 1) % 5]) {
					cur = (cur + 1) % 5;
					cnt += cur == 0;
				} else if (st.find(s[i][k]) != st.end()) {
					tot ++;
				}
			}
			dp[i & 1][cur] = max(dp[i & 1][cur], dp[~i & 1][j] + j + 5 * cnt - (tot + cur));
		}
	}

	int mx = 0;
	for (int i = 0; i < 5; i ++) {
		mx = max(mx, dp[n & 1][i]);
	}
	cout << mx << '\n';
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