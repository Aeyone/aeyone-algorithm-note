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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	if (k >= 3) {
		cout << 0 << '\n';
		return;
	}
	ranges::sort(a);
	int mn = a[0];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			int d = a[i] - a[j];
			mn = min(mn, d);
			if (k == 2) {
				int idx = ranges::lower_bound(a, d) - a.begin();
				if (idx > 0) {
					mn = min(mn, d - a[idx - 1]);
				}
				if (idx < n) {
					mn = min(mn, a[idx] - d);
				}
			}
		}
	}
	cout << mn << '\n';
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