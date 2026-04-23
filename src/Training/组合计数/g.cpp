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
	vector<int> p(m);
	for (int i = 0; i < m; i ++) {
		cin >> p[i];
	}
	i64 ans = 0;
	for (int mask = 1; mask < 1 << m; mask ++) {
		int num = n;
		for (int i = 0; i < m; i ++) if (mask >> i & 1) {
			num /= p[i];
		}
		// cerr << "num = " << num << '\n';
		ans += num * (__builtin_popcount(mask) & 1 ? 1 : -1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}