#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0, mn = INF, mx = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	cout << mx << ' ' << mn << ' ' << sum / n << '\n';
	vector<int> v;
	for (int i = 0; i < n; i ++) {
		if (a[i] > sum / n * 2) {
			v.push_back(i + 1);
		}
	}
	if (v.size() == 0) {
		cout << "Normal" << '\n';
	} else {
		for (int i = 0; i < v.size() - 1; i ++) {
			cout << v[i] << ' ';
		}
		cout << v.back() << '\n';
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