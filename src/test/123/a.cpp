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
	vector<int> n(1);
	cin >> n[0];
	if ((n[0] % 4) == 0) {
		cout << 0 << '\n';
		return;
	}
	while (n.back() >= 4) {
		int cur = n.back();
		n.push_back(cur / 5 + ((cur % 5) == 4 ? 0 : (cur % 5)));
	}
	int m = n.back();
	vector<int> ans(m);
	iota(ans.begin(), ans.end(), 1);
	for (int i = n.size() - 2; i >= 0; i --) {
		for (int j = 0; j < m; j ++) {
			if (5ll * ans[j] <= n[i]) {
				ans[j] *= 5;
			} else {
				ans[j] = n[i] - (m - j - 1);
			}
		}
	}
	cout << m << '\n';
	for (auto e : ans) {
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}