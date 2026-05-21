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
	int n, k;
	cin >> n >> k;
	vector<int> a(n), id(n, 1);

	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	auto v = a;
	iota(v.begin(), v.end(), 0);
	sort(v.begin(), v.end(), [&](const int &p, const int &q)-> bool {
		return a[p] > a[q];
	});

	int cur = 1, i = 0;
	for (; i < n && a[v[i]] > 0 && cur <= k; i ++) {
		if (v[i] == n - 1) continue;
		id[v[i]] = cur ++;
	}
	for (; i < n && a[v[i]] > 0 && cur > 2; i ++) {
		if (v[i] == n - 1) continue;
		id[v[i]] = -- cur;
	}

	vector<vector<int>> nums(k + 1);
	for (int i = 0; i < n; i ++) {
		nums[id[i]].push_back(a[i]);
	}

	i64 ans = 0;
	for (int i = 1; i <= k; i ++) {
		if (!nums[i].size()) continue;
		int mx = -INF;
		for (int j = 0; j < nums[i].size() - 1; j ++) mx = max(mx, nums[i][j]);
		ans += (nums[i].size() > 1 ? mx : 0) + nums[i].back();
	}

	cout << ans << '\n';
	for (auto e : id) cout << e << ' ';
	cout << '\n';
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