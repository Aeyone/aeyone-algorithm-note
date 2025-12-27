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
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}
	int k;
	cin >> k;
	vector<int> ans(n);
	auto dfs = [&](auto &&self, int cur, int num, int idx)->void{
		if (idx >= n || cur == 0) {
			return;
		}
		int mx = 0, _idx = idx;
		for (int i = idx; i < n; i ++) {
			if (cur / (c[i] - num) >= mx) {
				mx = cur / (c[i] - num);
				_idx = i;
			}
		}
		for (int i = idx; i <= _idx; i ++) {
			ans[i] = mx;
		}
		self(self, cur % (c[_idx] - num), c[_idx], _idx + 1);
	};
	dfs(dfs, k, 0, 0);
	for (auto e : ans) {
		cout << e << ' ';
	}
	cout << '\n';
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