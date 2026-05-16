#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n), b(n), c(n);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}
	for (auto &e : c) {
		cin >> e;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	multiset<i64> ans1;
	for (int i = 0; i < min(n, m); i ++) {
		ans1.insert(a[i]);
	}
	multiset<i64> ans2;
	for (int i = 0; i < n; i ++) {
		for (auto e : ans1) {
			if (ans2.size() == m && b[i] * e > *(--ans2.end())) {
				break;
			}
			ans2.insert(b[i] * e);
			if (ans2.size() > m) {
				ans2.erase(ans2.find(*(--ans2.end())));
			}
		}
	}
	multiset<i64> ans3;
	for (int i = 0; i < n; i ++) {
		for (auto e : ans2) {
			if (ans3.size() == m && c[i] * e > *(--ans3.end())) {
				break;
			}
			ans3.insert(c[i] * e);
			if (ans3.size() > m) {
				ans3.erase(ans3.find(*(--ans3.end())));
			}
		}
	}
	for (auto e : ans3) {
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