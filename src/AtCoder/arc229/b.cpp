#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
	
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	bool ok = true;
	int ans = (a[0] != 0);
	for (int i = 0; i < n; i ++) {
		if (i) {
			ok &= (a[i - 1] >= a[i] * 2);
			ans = max(ans, a[i - 1] - a[i] * 2);
		}
	}
	if (!ok) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}