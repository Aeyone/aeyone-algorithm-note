#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(auto &e : a)
		cin >> e;

	sort(a.begin(), a.end());
	vector<i64> s(m);
	s[0] = min(n - 1, a[0]);
	i64 ans = 0;
	for(int i = 1; i < m; i ++){
		int l = 0, r = i - 1, tar = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[mid] + a[i] >= n)
				tar = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		int need = max(0, n - a[i] - 1);
		if(tar != -1)
			ans += 2 * (s[i - 1] - (tar > 0 ? s[tar - 1] : 0) - (i64)(i - tar) * need);

		s[i] = s[i - 1] + min(n - 1, a[i]);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}