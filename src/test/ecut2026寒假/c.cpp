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
	string s, t;
	cin >> s >> t;
	set<char> st;
	for (auto e : s) {
		st.insert(e);
	}
	int n = t.size();
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		a[i] = (st.find(t[i]) != st.end());
	}
	int cnt = 0;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && a[r] == a[l]) {
			r ++;
		}
		cnt += a[l];
	}
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}