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
	int n, c, k;
	cin >> n >> c >> k;
	vector<i64> a(n);
	for (auto& e : a) {
		cin >> e;
	}
	ranges::sort(a);
	i64 ans = c;
	for (auto e : a) {
		if (e < ans && k > 0) {
			i64 x = min(e + k, ans);
			k -= (x - e);
			e = x;
		}
		if (ans >= e) {
			ans += e;
		}
	}
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