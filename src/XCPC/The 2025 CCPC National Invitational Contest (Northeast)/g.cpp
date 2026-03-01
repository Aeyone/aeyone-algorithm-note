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
	vector<int> du(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		du[u] ++;
		du[v] ++;
	}
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; i ++) {
		if (du[i] & 1) {
			cnt ++;
			ans.push_back(i + 1);
		}
	}
	cout << cnt / 2 << '\n';
	for (int i = 0; i < ans.size(); i += 2) {
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
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