#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	if(count(a.begin(), a.end(), a[0]) == n){
		cout << 2 * a[0] << '\n';
		return;
	}
	int u = -1, mn = inf;
	i64 res = 0;
	for(int i = 0; i < n; i ++){
		mn = min(mn, a[i]);
		res += mn;
		if(mn != inf && a[i] > mn)
			break;
	}
	
	cout << min((i64)a[0] + a[1], res) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}