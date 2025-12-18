#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	i64 sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];
	if(sum <= m)
		cout << "Yes" <<  '\n';
	else
		cout << "No" << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}