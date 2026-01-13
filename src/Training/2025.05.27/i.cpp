#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, v;
	cin >> n >> m >> v;
	if(m < n - 1 || (m - 1) > (n - 2) * (n - 1) / 2){
		cout << -1 << '\n';
		return;
	}
	int st = (v == 1 ? 2 : 1);
	cout << st << " " << v << '\n';

	for(int i = 1; i <= n; i ++){
		if(i == v || i == st)
			continue;
		cout << v << " " << i << '\n';
	}
	m -= n - 1;
	for(int i = 1; i <= n; i ++){
		if(i == v || i == st)
			continue;
		for(int j = i + 1; j <= n; j ++){
			if(!m)
				return;
			if(j == v || j == st)
				continue;
			cout << i << " " << j << '\n';
			m --;
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}