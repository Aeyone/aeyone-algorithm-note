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
	vector<int> vis(n + 1), ans(m);
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		if (vis[x]) {
			continue;
		}
		for (int j = x; j <= n; j += x) {
			if (!vis[j]) {
				vis[j] = true;
				ans[i] ++;
			}
		}
	}
	for (int i = 0; i < m; i ++) {
		if (ans[i] == 0) {
			cout << "the lights are already on!" << '\n';
		} else {
			cout << ans[i] << '\n';
		}
	}
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