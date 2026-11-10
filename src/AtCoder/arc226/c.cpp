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
	int k = (n & -2) * (m & -2) / 4;
	cout << k << '\n';
	for (int i = 1; i < n; i += 2) {
		for (int j = 1; j < m; j += 2) {
			cout << i << ' ' << j << ' ' << 1 << '\n';
		}
	}
	
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}