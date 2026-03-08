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
	vector<int> a(n), p(n), idx(n + 1);
	for (int i = 0; i < n; i ++) {
		cin >> p[i];
		idx[p[i]] = i;
	}
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> v;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && a[r] == a[l]) {
			r ++;
		}
		v.push_back(idx[a[l]]);
	}
	bool ok = true;
	for (int i = 1; i < v.size(); i ++) {
		ok &= (v[i] > v[i - 1]);
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