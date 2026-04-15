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
	int n, k;
	cin >> n >> k;
	vector<int> w(n), t(n);
	for (int i = 0; i < n; i ++) {
		cin >> w[i] >> t[i];
	}
	vector<int> idx(n);
	ranges::iota(idx, 0);
	ranges::sort(idx, [&](const int& a, const int& b)-> bool {
		return t[a] < t[b];
	});

	map<int, int> mp;
	int ans = 0;
	for (auto e : idx) {
		int cnt = mp[w[e] - t[e]];
		ans = max(ans, (k  - w[e]) + t[e] + cnt);
		cout << "cnt = " << cnt << '\n';
		mp[w[e] - t[e] + cnt] ++;
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