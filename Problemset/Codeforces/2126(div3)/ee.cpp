#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int x = a[0];
	for(int i = 0; i < n; i ++){
		x = __gcd(x, a[i]);
		cout << __gcd(x, a[i]) << ' ';
	}
	x = a[n - 1];
	cout << '\n';
	vector<int> b;
	for(int i = n - 1; i >= 0; i --){
		x = __gcd(x, a[i]);
		b.push_back(x);
	}
	for(int i = n - 1; i >= 0; i --)
		cout << b[i] << ' ';
	
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}