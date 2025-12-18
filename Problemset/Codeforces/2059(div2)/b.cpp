#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	if(n == k){
		int x = n / 2 + 1;
		for(int i = 1; i < n; i += 2)
			if(a[i] != (i + 1) / 2){
				x = (i + 1) / 2;
				break;
			}
		cout << x << '\n';
	}else{
		bool ok = true;
		for(int i = 1; i <= n - k + 1; i ++)
			ok &= (a[i] == 1);
		if(ok)
			cout << 2 << '\n';
		else
			cout << 1 << '\n';
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