#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> vis(100001, -1);
	for (int i = 0; i < n; i ++) {
		int x, c;
		cin >> x >> c;
		vis[x] = max(vis[x], c);
	}
	vector<int> v;
	for (int i = 1; i <= 100000; i ++) {
		if (vis[i] == 0) {
			v.push_back(i);
		}
	}
	if (v.size() == 0) {
		cout << "NONE" << '\n';
		return;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i ++) {
		cout << v[i] << ' ';
	}
	cout << v.back() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}