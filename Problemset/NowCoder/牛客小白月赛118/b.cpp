#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int len = 1;
	vector<int> res;
	for(int i = 1; i < n; i ++){
		i64 g = __gcd(a[i - 1], a[i]);
		if(g == 1){
			g = a[i];
			res.push_back(len);
			len = 1;
		}else
			len ++;
	}
	res.push_back(len);
	int cnt = 0;
	for(auto e : res)
		cnt += e / 2;
		// cout << e << ' ';
	// cout << '\n';
	cout << cnt << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}