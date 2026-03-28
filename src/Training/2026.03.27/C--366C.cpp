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
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
		b[i] *= -k;
	}
	map<int, int> mp;
	for (int i = 0; i < n; i ++) {
		vector<array<int, 2>> v = {{a[i] + b[i], a[i]}};
		for (auto [e, cost] : mp) {
			v.push_back({a[i] + b[i] + e, cost + a[i]});
		}
		for (auto [e, cost] : v) {
			mp[e] = max(mp[e], cost);
		}
	}
	if (mp.find(0) != mp.end()) {
		cout << mp[0] << '\n';
	} else {
		cout << -1 << '\n';
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