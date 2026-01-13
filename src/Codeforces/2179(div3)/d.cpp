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
	int n;
	cin >> n;
	vector<int> ans, vis(1 << n);
	for (int i = n - 1, cur = (1 << n) - 1; i >= 0; i --) {
		for (int j = 0; j < 1 << (n - i - 1); j ++) {
			if (!vis[cur ^ (j << i + 1)]) {
				ans.push_back(cur ^ (j << i + 1));
				vis[cur ^ (j << i + 1)] = true;
			}
		}
		cur ^= (1 << i);
	}
	for (int i = 0; i < 1 << n; i ++) {
		if (!vis[i]) {
			ans.push_back(i);
		}
	}
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