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
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 3>> q(m);
	for (auto &[x, y, z] : q) cin >> x >> y >> z;

	vector<int> a(n);

	for (int i = k; i >= 0; i --) {
		for (auto [x, y, z] : q) if (z >> i & 1) {
			
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