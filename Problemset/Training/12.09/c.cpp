#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//循环位移经典trick
	int n;
	cin >> n;
	vector<string> g(n);
	int tot = 0;
	for(int i = 0; i < n; i ++) {
		cin >> g[i];
		tot += count(g[i].begin(), g[i].end(), '1');
	}
	vector<int> cnt(n);
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			cnt[(n - i) % n] += (g[(i + j) % n][j] == '1');
		}
	}
	int ans = INF;
	for(int i = 0; i < n; i ++) {
		ans = min(ans, n + tot - 2 * cnt[i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}