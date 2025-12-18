#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	i64 sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += i;
	if(sum & 1){
		cout << -1 << '\n';
		return;
	}

	if(n & 1){
		i64 mid = sum / 2;
		int l = 1, r = n - 1;
		i64 s = n;
		while(s < mid)
			s += ((l ++) + (r --));

		for(int i = 1; i < l; i ++)
			cout << i << ' ';
		for(int i = r + 1; i <= n; i ++)
			cout << i << ' ';
		for(int i = l; i <= r; i ++)
			cout << i << ' ';
		cout << '\n';
	}else{
		int l = n / 4, r = n - l;
		for(int i = 1; i <= l; i ++)
			cout << i << ' ';
		for(int i = r + 1; i <= n; i ++)
			cout << i << ' ';
		for(int i = l + 1; i <= r; i ++)
			cout << i << ' ';
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