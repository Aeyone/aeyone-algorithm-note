#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 676767677;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &e : a) cin >> e;

	i64 ans = 0;
	for (auto e : a) {
		if (e != 1) {
			ans += e;
		}
	}
	ans += a.back() == 1;
	cout << ans << '\n';
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