#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if(x > y)
		swap(x, y);
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		res[(x - 1 + i) % n] = (i & 1);
	}
	if(n & 1)
		res[(x - 1 + n) % n] = 2;

	if(res[x - 1] == res[y - 1])
		res[y - 1] = 2;
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
	
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}