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
	vector<int> a(7);
	int sum = 0;
	for (int i = 0; i < 7; i ++) {
		cin >> a[i];
		sum -= a[i];
	}
	int ans = -INF;
	for (int i = 0; i < 7; i ++) {
		ans = max(ans, sum + 2 * a[i]);
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