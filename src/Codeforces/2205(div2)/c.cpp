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
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i ++) {
		int l;
		cin >> l;
		vector<int> v;
		for (int j = 0; j < l; j ++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		ranges::reverse(v);
		map<int, bool> mp;
		for (auto e : v) {
			if (!mp[e]) {
				mp[e] = true;
				a[i].push_back(e);
			}
		}
	}
	vector<int> ok(n), ans;
	map<int, bool> vis;
	for (int cur = 0; cur < n; cur ++) {
		int idx = -1;
		for (int i = 0; i < n; i ++) {
			if (ok[i]) {
				continue;
			}
			if (idx == -1 || a[i] < a[idx]) {
				idx = i;
			}
		}
		ok[idx] = true;
		for (auto e : a[idx]) {
			vis[e] = true;
			ans.push_back(e);
		}
		vector<vector<int>> b(n);
		for (int i = 0; i < n; i ++) {
			if (ok[i]) {
				continue;
			}
			for (auto e : a[i]) {
				if (!vis[e]) {
					b[i].push_back(e);
				}
			}
		}
		a = b;
	}
	for (auto e : ans) {
		cout << e << ' ';
	}
	cout << '\n';
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