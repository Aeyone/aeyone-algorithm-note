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
	int n;
	cin >> n;
	vector<int> a(n), b;
	set<int> st;
	int mn = INF, mx = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i ++) {
		if (a[i] != b[i]) {
			st.insert(a[i]);
		}
	}
	if (!st.size()) {
		cout << -1 << '\n';
		return;
	}
	int ans = INF;
	for (auto e : st) {
		ans = min(ans, max(e - mn, mx - e));
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