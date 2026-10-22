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
	set<int> st;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		st.insert(i);
	}
	vector<int> ans(n);
	sort(a.begin(), a.end(), greater<int>{});
	for (auto e : a) {
		auto it = st.lower_bound(e);
		if (it != st.end()) {
			ans[*it] = e;
			st.erase(it);
		} else {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
	for (auto e : ans) {
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}