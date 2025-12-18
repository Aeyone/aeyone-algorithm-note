#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), res(n, -1);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int x = 0, p = n - 1;
	while(p >= 0 && x < q)//设一开始iq为0 从后往前找
		x += (a[p --] > x);

	for(int i = 0; i < n; i ++){
		if(i <= p)
			cout << (a[i] <= q);
		else
			cout << 1;
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}