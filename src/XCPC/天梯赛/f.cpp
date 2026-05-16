#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	vector<int> ans(11);
	for (int i = 0; i < 11; i ++) {
		string s;
		getline(cin, s);
		ans[i] = s.size();
	}
	for (auto e : ans) {
		cout << e;
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}