#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	if(a[0] > a[n - 1])
		reverse(a.begin(), a.end());

	bool ok = true;
	int d = a[1] - a[0];
	for(int i = 1; i < n; i ++)
		ok &= (a[i] - a[i - 1] == d);

	int h = a[0] - d;
	if(!ok || h < 0 || h % (n + 1) != 0){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
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