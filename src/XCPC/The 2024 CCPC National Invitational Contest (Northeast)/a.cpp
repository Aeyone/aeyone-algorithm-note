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
	int x, k;
	cin >> x >> k;
	map<int, int> mp;
	mp[x] = k;
	while (x > 1 && k > 0) {
		k --;
		bool ok = (double)sqrt(x) == (int)sqrt(x);
		x = sqrt(x);
		if (ok) {
			mp[x] = 0;
		} else {
			mp[x] = k;
		}
	}
	i64 ans = 0;
	for (auto [e, c] : mp) {
		ans += (e == 1 ? 1 : c + 1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}