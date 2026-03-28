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
	vector<int> a(n), b(n);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}

	bool ok = true;
	for (int i = 0; i < n - k; i ++) {
		if (a[i] != a[i + k]) {
			ok &= (b[i] == -1 || a[i] == b[i]);
			ok &= (b[i + k] == -1 || a[i + k] == b[i + k]);
			b[i] = a[i];
			b[i + k] = a[i + k];
		}
	}

	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
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