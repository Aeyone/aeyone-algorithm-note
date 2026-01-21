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
	vector<map<int, int>> cnt(n);
	vector<int> mex(n);
	map<int, i64> to;
	i64 sum = 0;
	for (int i = 0; i < n; i ++) {
		int l;
		cin >> l;
		a[i].assign(l, 0);
		for (int j = 0; j < l; j ++) {
			cin >> a[i][j];
			cnt[i][a[i][j]] ++;
		}
		while (cnt[i].find(mex[i]) != cnt[i].end()) {
			mex[i] ++;
		}
		sum += mex[i];

		int tomex = mex[i] + 1;
		while (cnt[i].find(tomex) != cnt[i].end()) {
			tomex ++;
		}
		to[mex[i]] += tomex - mex[i];
	}
	i64 ans = 0;
	for (int i = 0; i < n; i ++) {
		for (auto e : a[i]) {
			ans += 1ll * (n - 1) * sum;
			if (cnt[i][e] == 1 && e < mex[i]) {
				ans -= 1ll * (n - 1) * (mex[i] - e);
			}
			if (to.find(e) != to.end()) {
				ans += to[e];
			}
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