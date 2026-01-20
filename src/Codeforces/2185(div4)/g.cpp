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
	vector<vector<int>> a(n);
	vector<i64> to(n + 2);
	map<int, int> mp;
	i64 sum = 0;
	for (int i = 0; i < n; i ++) {
		int l;
		cin >> l;
		a[i].assign(l, 0);
		set<int> st;
		for (int j = 0; j < l; j ++) {
			cin >> a[i][j];
			st.insert(a[i][j]);
		}
		int mex = 0;
		while (st.find(mex) != st.end()) {
			mex ++;
		}
		sum += mex;
		mp[mex] ++;

		int tomex = mex + 1;
		while (st.find(tomex) != st.end()) {
			tomex ++;
		}
		to[mex] += tomex;
	}
	i64 ans = 0;
	for (int i = 0; i < n; i ++) {
		ans += sum * a[i].size();
	}
	for (int i = 0; i < n; i ++) {
		for (auto e : a[i]) {
			if (mp.find(e) == mp.end()) {
				continue;
			}
			ans -= 1ll * mp[e] * e;
			ans += to[e];
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