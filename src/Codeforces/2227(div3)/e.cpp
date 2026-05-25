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
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	i64 ans = 0;
	vector<pair<int, int>> stk;
	for (int i = 0; i < n; i ++) {
		int cnt = 1;
		while (stk.size() && stk.back().first > a[i]) {
			ans += (stk.back().first - a[i]) * stk.back().second;
			cnt += stk.back().second;
			stk.pop_back();
		}
		stk.push_back({a[i], cnt});
	}
	int mx = 0, m = stk.size();
	for (int l = 0, r = 0; l < m; l = r) {
		int cnt = 0;
		while (r < m && stk[l].first == stk[r].first) {
			cnt += stk[r].second;
			r ++;
		}
		mx = max(mx, cnt - 1);
	}

	cout << ans + mx << '\n';
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