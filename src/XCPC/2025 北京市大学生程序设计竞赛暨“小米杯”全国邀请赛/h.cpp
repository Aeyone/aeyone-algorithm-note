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
	int n, m, p;
	cin >> n >> m >> p;
	using T = bitset<1000>;
	vector<T> a(1000), b(1000), c(1000);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int x;
			cin >> x;
			a[i][j] = x;
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < p; j ++) {
			int x;
			cin >> x;
			c[i][j] = x;
		}
	}
	unordered_map<T, int> mp;
	for (int i = 0; i < m; i ++) {
		T e;
		for (int j = 0; j < n; j ++) {
			e[j] = a[j][i];
		}
		mp[e] = i;
	}
	for (int i = 0; i < p; i ++) {
		T e;
		bool ok = true;
		for (int j = 0; j < n; j ++) {
			e[j] = c[j][i];
			ok &= (e[j] == 0);
		}
		if (ok) {
			continue;
		}
		if (mp.find(e) != mp.end()) {
			b[mp[e]][i] = 1;
		} else {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < p; j ++) {
			int x = b[i][j];
			cout << x << ' ';
		}
		cout << '\n';
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