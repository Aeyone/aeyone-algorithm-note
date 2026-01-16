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
	vector<int> a(n), d(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<int>> idx(n + 1);
	for (int i = 1; i < n; i ++) {
		d[i] = abs(a[i] - a[i - 1]);
		idx[d[i]].push_back(i);
	}
	set<pair<int, int>> seg = {{1, n - 1}};
	i64 cur = 1ll * n * (n - 1) / 2;
	vector<i64> ans(n);
	for (int i = 1; i <= n - 1; i ++) {
		ans[i] = cur;
		for (auto e : idx[i]) {
			auto it = --seg.lower_bound(array<int, 2>{e, INF});
			auto [l, r] = *it;
			seg.erase(it);
			cur -= 1ll * (r - l + 2) * (r - l + 1) / 2;
			if (l <= e - 1){
				seg.insert({l, e - 1});
				cur += 1ll * ((e - 1) - l + 2) * ((e - 1) - l + 1) / 2;
			}
			if (e + 1 <= r) {
				seg.insert({e + 1, r});
				cur += 1ll * (r - (e + 1) + 2) * (r - (e + 1) + 1) / 2;
			}
		}
	}
	for (int i = 1; i <= n - 1; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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