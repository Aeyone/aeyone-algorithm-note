#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	double x0, y0, sum = 0;
	cin >> x0 >> y0;
	for(int i = 1; i < n; i ++){
		double x, y;
		cin >> x >> y;
		double d = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
		double l = 0, r = 60;
		while(r - l >= 1e-8){
			double m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
			double a1 = m1 + d / pow(2, m1), a2 = m2 + d / pow(2, m2);
			if(a1 > a2)
				l = m1;
			if(a2 > a1)
				r = m2;
			if(a1 == a2)
				l = m1, r = m2;
		}
		x0 = x, y0 = y;
		sum += (2 * (l + d / pow(2, l)));
	}
	printf("%.8lf\n", sum);
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}