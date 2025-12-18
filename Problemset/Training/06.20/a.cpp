#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0, r = n - 1;
	i64 x = 0, ans = 0;
	while(l < r){
		while(l < r && x + a[l] < a[r])
			ans += a[l], x += a[l ++];

		if(l == r)
			break;
		// cout << l << ' ' << r << ' ' << x << '\n';
		ans += (a[r] - x);
		a[l] -= (a[r --] - x);//a[l] >= 0
		x = 0;
		ans ++;
	}
	// cout << l << ' '  << r << '\n';
	if(a[r] >= 2){
		i64 res = (x + a[r]);
		ans += (res / 2 - x + 1 + (res & 1));
	}else
		ans += a[r];
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