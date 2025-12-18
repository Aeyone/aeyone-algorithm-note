#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int r = n - 1;
	i64 ans = -100000;
	while(r){
		if(a.back() - a.front() < a.front() - a.back())
			reverse(a.begin(), a.end());
		i64 sum = 0;
		for(auto e : a)
			sum += e;
		ans = max(ans, sum);
		for(int i = 0; i < r; i ++)
			a[i] = a[i + 1] - a[i];
		a.pop_back();
		r --;
	}
	cout << max(ans, a[0]) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}