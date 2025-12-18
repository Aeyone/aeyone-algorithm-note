#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 x = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], x ^= a[i];

	int cnt = 0;
	i64 tmp = 0; 
	for(int i = 0; i < n; i ++){
		tmp ^= a[i];
		if(tmp == x)
			tmp = 0, cnt ++;
	}
	if(x == 0 || cnt >= 2)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}
