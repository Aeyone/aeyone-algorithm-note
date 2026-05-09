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
	vector<int> a(n + 1);
	vector<vector<int>> v(2);
	array<int, 2> mx = {0, 0}, mn = {INF, INF};

	bool ok = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		int c = a[i] & 1;
		if (v[c].size() && v[c].back() > a[i]) {
			ok &= (mn[c ^ 1] < a[i] || mx[c ^ 1] > v[c].back());
		}
		v[c].push_back(a[i]);
		mx[c] = max(mx[c], a[i]);
		mn[c] = min(mn[c], a[i]);
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