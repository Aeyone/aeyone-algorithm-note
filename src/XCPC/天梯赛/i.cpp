#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n, t;
	cin >> n >> t;
	vector<array<int, 2>> a(n);
	vector<int> ans;
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}
	while (1) {
		vector<array<int, 2>> cur;
		int sum = 0;
		for (int i = 0; i < a.size(); i ++) {
			auto [x, idx] = a[i];
			if (x <= t) {
				ans.push_back(idx);
			} else {
				sum += x;
				cur.push_back(a[i]);
			}
		}
		if (cur.size() == 0) {
			break;
		}
		reverse(cur.begin(), cur.end());
		a = cur;
		t = sum / a.size();
	}
	for (int i = 0; i < n - 1; i ++) {
		cout << ans[i] << ' ';
	}
	cout << ans.back() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}