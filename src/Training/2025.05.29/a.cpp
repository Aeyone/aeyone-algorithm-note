#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int cnt = 0;
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			if(abs(a[i] - a[j]) <= d)
				cnt ++;
	cout << cnt * 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}