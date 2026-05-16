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
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<i64> suf(n + 2);
	for (int i = n; i >= 1; i --) {
		suf[i] = suf[i + 1] + a[i];
	}

	multiset<i64> st;
	i64 ans = -INFLL;
	for (int i = 1; i <= n; i ++) {
		st.insert(suf[i]);
		if (i - m >= 1) {
			st.erase(st.find(suf[i - m]));
		}
		ans = max(ans, *(--st.end()) - suf[i + 1]);
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