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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n + 1), p1, p2;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i >= x + 1 && i <= y) {
			p1.push_back(a[i]);
		} else {
			p2.push_back(a[i]);
		}
	}
	int m = p1.size(), idx = ranges::min_element(p1) - p1.begin();
	vector<int> t;
	for (int i = idx; i < p1.size(); i ++) {
		t.push_back(p1[i]);
	}
	for (int i = 0; i < idx; i ++) {
		t.push_back(p1[i]);
	}

	int cur = 0;
	while (cur < p2.size() && p2[cur] < t[0]) {
		cur ++;
	}
	for (int i = 0; i < cur; i ++) {
		cout << p2[i] << ' ';
	}
	for (auto e : t) {
		cout << e << ' ';
	}
	for (int i = cur; i < p2.size(); i ++) {
		cout << p2[i] << ' ';
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