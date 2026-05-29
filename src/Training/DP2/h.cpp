#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> t(n + 1), c(n + 1), st(n + 1), sc(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> t[i] >> c[i];
		st[i] = st[i - 1] + t[i];
		sc[i] = sc[i - 1] + c[i];
	}

	vector<int> dp(n + 1, INFLL); // dp[i]表示将前i个任务中分成任意组的最小花费
	deque<int> q;
	dp[0] = 0;
	q.push_back(0);

	auto check = [&](int i, int j, int x)-> bool { // 满足条件 选i更优
		return i128(x) * (sc[i] - sc[j]) >= i128(dp[i] - dp[j]);
	};

	auto ckback = [&](int i, int j, int k)-> bool {
		return i128(dp[i] - dp[j]) * (sc[j] - sc[k]) >= i128(dp[j] - dp[k]) * (sc[i] - sc[j]);
	};

	for (int i = 1; i <= n; i ++) {
		int l = 0, r = q.size() - 2, j = q.back();
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(q[mid], q[mid + 1], st[i] + s)) {
				j = q[mid], r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		dp[i] = dp[j] + st[i] * (sc[i] - sc[j]) + s * (sc[n] - sc[j]);

		while (q.size() >= 2 && ckback(q[q.size() - 2], q[q.size() - 1], i)) {
			q.pop_back();
		}
		q.push_back(i);
	}
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