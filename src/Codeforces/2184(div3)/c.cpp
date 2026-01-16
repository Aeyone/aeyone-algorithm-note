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
	int n, k;
	cin >> n >> k;
	int ans = INF;
	map<int, bool> mp;
	auto dfs = [&](auto &&self, int cur, int cnt)->void{
		if (cur == k) {
			ans = min(ans, cnt);
		}
		if (cur == 1 || mp[cur]) {
			return;
		}
		mp[cur] = true;
		self(self, cur / 2, cnt + 1);
		self(self, (cur + 1) / 2, cnt + 1);
	};
	dfs(dfs, n, 0);
	cout << (ans == INF ? -1 : ans) << '\n';
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