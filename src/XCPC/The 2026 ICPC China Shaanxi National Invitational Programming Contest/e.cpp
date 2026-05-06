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
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		mp[a[i]] ++;
	}
	int ans = 0;
	for (auto [e, c] : mp) {
		if (c <= x) {
			ans += c;
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