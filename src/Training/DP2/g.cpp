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
	int n, s;
	cin >> n >> s;
	vector<i64> t(n + 1), c(n + 1), st(n + 1), sc(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> t[i] >> c[i];
		st[i] = st[i - 1] + t[i];
		sc[i] = sc[i - 1] + c[i];
	}

	vector<i64> dp(n + 1, INFLL); // dp[i]表示将前i个任务中分成任意组的最小花费
	deque<int> q;
	dp[0] = 0;
	q.push_back(0);

	auto ckfront = [&](int i, int j, i64 x)-> bool {
		return x * (sc[i] - sc[j]) <= (dp[i] - dp[j]);
	};

	auto ckback = [&](int i, int j, int k)-> bool {
		return (dp[i] - dp[j]) * (sc[j] - sc[k]) >= (dp[j] - dp[k]) * (sc[i] - sc[j]);
	};

	for (int i = 1; i <= n; i ++) {
		while (q.size() >= 2 && ckfront(q[0], q[1], st[i] + s)) {
			q.pop_front();
		}
		int j = q[0];
		dp[i] = dp[j] + st[i] * (sc[i] - sc[j]) + 1ll * s * (sc[n] - sc[j]);

		while (q.size() >= 2 && ckback(q[q.size() - 2], q[q.size() - 1], i)) {
			q.pop_back();
		}
		q.push_back(i);
	}
	for (int i = 1; i <= n; i ++) {
		cerr << dp[i] << ' ';
	}
	cerr << '\n';
	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}