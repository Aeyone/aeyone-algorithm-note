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
	int n, m;
	while (cin >> n >> m) {
		vector<int> c(n + 1), sc(n + 1);
		for (int i = 1; i <= n; i ++) {
			cin >> c[i];
			sc[i] = sc[i - 1] + c[i];
		}
		vector<int> dp(n + 1);
		deque<int> q;
		q.push_back(0);

		auto up = [&](int i, int j)-> int {
			return (dp[i] + sc[i] * sc[i]) - (dp[j] + sc[j] * sc[j]);
		};

		auto down = [&](int i, int j)-> int {
			return (sc[i] - sc[j]);
		};

		for (int i = 1; i <= n; i ++) {
			while (q.size() >= 2 && i128(2 * sc[i]) * down(q[0], q[1]) <= up(q[0], q[1])) {
				q.pop_front();
			}
			int j = q[0];
			dp[i] = dp[j] + (sc[i] - sc[j]) * (sc[i] - sc[j]) + m;
			int siz = q.size();
			while (q.size() >= 2 && (i128)up(q[siz - 2], q[siz - 1]) * down(q[siz - 1], i) >= (i128)up(q[siz - 1], i) * down(q[siz - 2], q[siz - 1])) {
				q.pop_back();
				siz --;
			}
			q.push_back(i);
		}
		cout << dp[n] << '\n';
	}
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