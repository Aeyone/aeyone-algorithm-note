#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> res;
	i64 x = 1;
	res.push_back(1);
	for(int i = 2; i < n; i ++){
		if(__gcd(i, n) == 1){
			x = (x * i) % n;
			res.push_back(i);
		}
	}
	if(x == 1)
		cout << res.size() << '\n';
	else
		cout << res.size() - 1 << '\n';
	for(auto e : res)
		if(x != e || e == 1)
			cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}