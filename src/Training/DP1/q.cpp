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
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	vector<i64> suf(2 * n + 2);
	for (int i = 2 * n; i >= 1; i --) {
		suf[i] = suf[i + 1] + a[i];
	}

	multiset<i64> st;
	i64 ans = 0;
	for (int i = 1; i <= 2 * n; i ++) {
		st.insert(suf[i]);
		if (i - n >= 1) {
			st.erase(st.find(suf[i - n]));
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