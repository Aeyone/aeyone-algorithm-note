#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
const double pi = 3.141592653589793;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<double> a(n);
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		if(x == 0){
			a[i] = pi / 2 + (y < 0 ? pi : 0);
		}else{
			a[i] = atan((double)abs(y) / abs(x));
			if(x < 0 && y >= 0){
				a[i] = pi - a[i];
			}
			if(x < 0 && y < 0){
				a[i] = pi + a[i];
			}
			if(x > 0 && y < 0){
				a[i] = pi + (pi - a[i]);
			}
		}
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < k; i ++){
		a.push_back(a[i] + 2 * pi);
	}
	// for(auto e : a){
	// 	cout << e / (2 * pi) * 360 << '\n';
	// }
	double ans = 0;
	for(int i = k; i < n + k; i ++){
		ans = max(ans, a[i] - a[i - k]);
	}
	printf("%.8lf\n", ans);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}