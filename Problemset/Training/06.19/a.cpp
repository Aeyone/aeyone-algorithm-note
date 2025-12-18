#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1, 0);
	for(int i = 1; i <= n; i ++)
		cin >> a[i], b[i] = (a[i] == i);

	int c[2] = {};
	c[b[1]] ++;
	for(int i = 2; i <= n; i ++){
		if(b[i] != b[i - 1])
			c[b[i]] ++;
	}
	if(c[0] == 0)
		cout << 0 << '\n';
	else if(c[0] == 1)
		cout << 1 << '\n';
	else
		cout << 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}