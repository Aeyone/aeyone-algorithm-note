#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 1e3 + 10;

int dp[N][N];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < n; j ++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = 0; j < n; j ++) {
			if (dp[i - 1][j] != -1) {
				dp[i][(j + a[i]) % n] = i;
			}
		}
	}
	if (dp[n][0] == 0) {
		cout << "No Solution" << '\n';
		return;
	}
	int idx = dp[n][0], cur = 0;
	vector<int> ans;
	while (idx > 0) {
		ans.push_back(idx);
		cur = (cur - (a[idx] % n) + n) % n;
		idx = dp[idx - 1][cur];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << a[e] << '\n';
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