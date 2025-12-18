#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b1(n), b2(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	i64 c1 = 0, c2 = 0;
	for(int i = 0; i < n; i ++){
		if(i & 1)
			b1[i] = 1, b2[i] = a[i];
		else
			b1[i] = a[i], b2[i] = 1;
		c1 += abs(a[i] - b1[i]);
		c2 += abs(a[i] - b2[i]);
	}
	
	if(c1 <= c2){
		for(auto e : b1)
			cout << e << ' ';
	}else{
		for(auto e : b2)
			cout << e << ' ';
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