#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int ans = (a[0] == 1);
	int cnt = 0;
	for(int i = 1; i < n; i ++){
		if(a[i] == 1)
			cnt ++;
		if(cnt && a[i] == 0)
			ans += cnt / 3, cnt = 0;
	}
	if(cnt)
		ans += cnt / 3;
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