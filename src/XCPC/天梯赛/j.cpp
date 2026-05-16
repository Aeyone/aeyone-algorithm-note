#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	int mx = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0];
		a[i][1] = i + 1;
		mx = max(mx, a[i][0]);
	}
	sort(a.begin(), a.end());
	vector<int> v;
	for (auto [e, idx] : a) {
		if (e == mx) {
			v.push_back(idx);
		}
	}
	for (int i = 0; i < v.size() - 1; i ++) {
		cout << v[i] << ' ';
	}
	cout << v.back() << '\n';
	int m;
	cin >> m;
	while (m --) {
		int x;
		cin >> x;
		int i = upper_bound(a.begin(), a.end(), array<int, 2>{x, INF}) - a.begin();
		if (i == n) {
			cout << 0 << '\n';
		} else {
			cout << a[i][1] << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}