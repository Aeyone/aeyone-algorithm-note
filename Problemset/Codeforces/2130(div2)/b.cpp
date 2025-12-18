#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	i64 sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];

	int d = s - sum;

	int c0 = count(a.begin(), a.end(), 0);
	int c1 = count(a.begin(), a.end(), 1);
	int c2 = count(a.begin(), a.end(), 2);
	string str;
	str = string(c0, '0') + string(c2, '2') + string(c1, '1');

	if(d == 0 || d > 1)
		cout << -1 << '\n';
	
	if(d < 0 || d == 1){
		for(auto e : str)
			cout << e << ' ';
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}