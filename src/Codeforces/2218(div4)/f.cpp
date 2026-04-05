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
	int x, y;
	cin >> x >> y;
	if (x > y || (!x && !(y & 1))) {
		cout << "NO" << '\n';
		return;
	}
	int n = x + y;
	vector<array<int, 2>> ans;
	cout << "YES" << '\n';
	if (!x) {
		for (int i = 2; i <= n; i ++) {
			ans.push_back({1, i});
		}
	} else {
		int d = y - x;
		for (int i = 1; i <= d; i ++) {
			ans.push_back({n, n - i});
		}
		int cur = n - d - 1;
		ans.push_back({n, cur});
		while (cur >= 2) {
			ans.push_back({cur, cur - 1});
			cur --;
		}
	}
	for (auto [u, v] : ans) {
		cout << u << ' ' << v << '\n';
	}

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