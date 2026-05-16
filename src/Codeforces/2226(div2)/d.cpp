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
	vector<int> a(n + 1);
	vector<vector<int>> v(2);
	array<int, 2> mx = {0, 0}, mn = {INF, INF};

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		v[a[i] & 1].push_back(a[i]);
		mx[a[i] & 1] = max(mx[a[i] & 1], a[i]);
		mn[a[i] & 1] = min(mn[a[i] & 1], a[i]);
	}

	bool ok = true;
	multiset<int> st;
	for (auto e : v[0]) {
		if (st.size()) {
			int max = *(--st.end());
			if (max > e) ok &= (mn[1] < e || mx[1] > max);
		}
		st.insert(e);
	}
	st.clear();
	for (auto e : v[1]) {
		if (st.size()) {
			int max = *(--st.end());
			if (max > e) ok &= (mn[0] < e || mx[0] > max);
		}
		st.insert(e);
	}
	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
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