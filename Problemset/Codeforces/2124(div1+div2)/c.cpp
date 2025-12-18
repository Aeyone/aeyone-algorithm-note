#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> b(n);
	for(int i = 0; i < n; i ++)
		cin >> b[i];
	bool ok = false;
	i64 ans = 1;
	for(int i = 0; i < n - 1; i ++){
		if(b[i + 1] % b[i] != 0){
			i64 g = __gcd(b[i], b[i + 1]);
			if(__gcd(b[i] / g, ans) != b[i] / g)
				ans *= b[i] / __gcd(b[i] / g, ans) / g;
				// cout << b[i] / g << ' ';
		}
	}
	cout << ans << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}