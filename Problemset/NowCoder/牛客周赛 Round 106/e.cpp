#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, sum;
	cin >> n >> sum;
	if(sum < n){
		cout << -1 << '\n';
		return;
	}
	vector<i64> a(n, 1);
	sum -= n;	
	i64 cnt = 1, x = 3;
	while(sum >= x){	
		for(int i = 0; i < n; i ++){
			if(sum >= x)
				a[i] += x, sum -= x;
		}
		x = cnt * 4;
		for(int i = 0; i < n; i ++){
			if(sum >= x)
				a[i] += x, sum -= x;
		}
		cnt *= 10;
		x = cnt * 4;
	}
	for(auto e : a)
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