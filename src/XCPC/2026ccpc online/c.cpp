#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL
typedef long double ld;
const ld eps = 1e-9;
const ld pi = acos(-1);
const ld INFld = 1e20;

void solve() {
	ld w, x1, x2, yc, u, v;
	cin >> w >> x1 >> x2 >> yc >> u >> v;
	ld t = yc / v;
	ld X1 = x1+t*u,X2 = x2+t*u;
	if (0 <= X1 || 0 >= X2) {
		cout << w / v << '\n';
		return;
	}
	auto calc = [&](ld x)-> bool {
		ld t = yc / sin(x) / v;
		ld X1 = x1+t*u,X2 = x2+t*u;
		ld cur = yc / tan(x);
		return (cur <= X1 || cur >= X2);
	};

	ld l = 0,r = pi/2;
	ld ans1 = -1;
	while(r-l>=eps){
		ld mid = (l + r) / 2;
		if (calc(mid)) {
			ans1 = mid, l = mid;
		} else {
			r = mid;
		}
	}

	l = pi / 2, r = pi;
	ld ans2 = -1;
	while(r-l>=eps){
		ld mid = (l + r) / 2;
		if (calc(mid)) {
			ans2 = mid, r = mid;
		} else {
			l = mid;
		}
	}

	ld ans = yc / sin(ans1) / v;
	if (ans2 != -1) {
		ans = min(ans, yc / sin(ans2) / v);
	}
	ans += (w - yc) / v;
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	cout<<fixed<<setprecision(10);
	while (t --) {
		solve();
	}
}