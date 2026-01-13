#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<i64, double>> a(n);
	bool ok = true;
	for(int i = 0; i < n; i ++){
		double x;
		cin >> x;
		int cnt = 0;
		while(x >= 1)
			cnt ++, x /= 10;
		a[i] = {cnt, x};
		if(i && pow(10, a[i].first) * a[i].second == 1 && a[i] < a[i - 1])
			ok = false;
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	int ans = 0;
	for(int i = 1; i < n; i ++){
		while(a[i].first < a[i - 1].first || (a[i].first == a[i - 1].first && a[i - 1].second - a[i].second > 1e-12)){
			ans ++;
			a[i].first *= 2;
			a[i].second *= a[i].second;
			while(a[i].second < 0.1)
				a[i].first --, a[i].second *= 10;
		}
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