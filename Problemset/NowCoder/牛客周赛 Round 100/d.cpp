#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), u(n + 1, -1), u1(n + 1);
	int mx = 0, mn = 0x3f3f3f3f;
	for(int i = 0; i < 2 * n; i ++){
		cin >> a[i];
		if(u[a[i]] != -1)
			u1[a[i]] = i, mn = min(mn, i);
		else
			u[a[i]] = i, mx = max(mx, i);
	}
	auto check = [&](vector<int> arr, int l, int r)->i64{
		i64 res = 0;
		swap(arr[l], arr[r]);
		vector<int> idx(n + 1);
		for(int j = 0; j < 2 * n; j ++)
			idx[arr[j]] = j;

		for(int j = 0; j < 2 * n; j ++)
			if(j != idx[arr[j]])
				res += (idx[arr[j]] - j - 1);
		return res;
	};
	i64 ans1 = check(a, mn, mx);
	i64 ans2 = check(a, 0, 0);
	cout << max(ans1, ans2) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}