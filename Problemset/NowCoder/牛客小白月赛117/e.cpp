#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	if(count(a.begin(), a.end(), a[0]) == n){
		cout << 0 << '\n';
		return;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	i64 cnt = 0;
	i64 ans = 0;
	int x = a.size();

	for(int i = 0; i < a.size(); i ++){
		a[i] = max(0LL, a[i] - cnt);
		if(a[i] == 0){
			x = a.size() - i;
			continue;
		}

		ans += (a[i] + x - 1) / x;
		cnt += ((a[i] + x - 1) / x) * x;
		x = a.size() - i;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}