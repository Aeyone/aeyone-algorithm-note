#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	int n, vb, vs;
	cin >> n >> vb >> vs;
	vector<i64> x(n);
	for(int i = 0; i < n; i ++)
		cin >> x[i];
	i64 a, b;
	cin >> a >> b;

	vector<double> d(n), dd(n);
	int ans = 1;
	for(int i = 1; i < n; i ++){
		d[i] = sqrt(((x[i] - a) * (x[i] - a) + b * b)) / vs + (double)x[i] / vb;
		dd[i] = sqrt(((x[i] - a) * (x[i] - a) + b * b));
		if(d[i] < d[ans])
			ans = i;
		else if(d[i] == d[ans] && dd[i] < dd[ans])
			ans = i;
		// cout << d[i] << "@\n";
	}
	cout << ans + 1<< '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}