#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), u(n + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i], u[a[i]] = i + 1;

	int x = -1, y = -1;
	for(int i = 1; i <= n; i ++){
		if(!u[i])
			x = i;
		else
			y = i;
	}

	if(x != -1){
		int t;

		cout << "? " << x << ' ' << y << '\n';
		cout.flush();
		cin >> t;
		if(t)
			cout << "! B" << '\n';
		else
			cout << "! A" << '\n';
	}else{
		int t1, t2;

		cout << "? " << u[1] << ' ' << u[n] << '\n';
		cout.flush();
		cin >> t1;

		cout << "? " << u[n] << ' ' << u[1] << '\n';
		cout.flush();
		cin >> t2;

		if(t1 == t2 && t1 >= n - 1)
			cout << "! B" << '\n';
		else
			cout << "! A" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}