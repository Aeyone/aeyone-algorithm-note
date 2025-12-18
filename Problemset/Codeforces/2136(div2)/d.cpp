#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> p(n);
	array<int, 2> u, d;
	u = {2 * inf, -2 * inf};
	d = {2 * inf, 2 * inf};
	for(auto &[x, y] : p){
		cin >> x >> y;
		i64 d1 = (x + 2e9) + (2e9 - y);//左上
		i64 d2 = (x + 2e9) + (y + 2e9);//左下

		if(d1 < (u[0] + 2e9) + (2e9 - u[1]))
			u = {x, y};
		if(d2 < (d[0] + 2e9) + (d[1] + 2e9))
			d = {x, y};
	}
	i64 Du, Dd, t;
	cout << "? L " << inf << endl;
	cin >> t;
	cout << "? L " << inf << endl;
	cin >> t;

	cout << "? U " << inf << endl;
	cin >> t;
	cout << "? U " << inf << endl;
	cin >> Du;

	cout << "? D " << inf << endl;
	cin >> t;
	cout << "? D " << inf << endl;
	cin >> t;
	cout << "? D " << inf << endl;
	cin >> t;
	cout << "? D " << inf << endl;
	cin >> Dd;

	i64 A = Du + Dd - 4ll * inf + (u[1] - d[1]);

	i64 dx = (A + u[0] - d[0]) / 2, dy = Du - dx;

	i64 X = u[0] + 2ll * inf - dx, Y = u[1] - 2ll * inf + dy;

	cout << "! " << X << ' ' << Y << endl;
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}