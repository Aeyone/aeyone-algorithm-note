#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	bool ok = true;
	int c1 = count(a.begin(), a.end(), -1);
	int c0 = count(a.begin(), a.end(), 0);
	int c11 = count(a.begin(), a.end(), 1);
	if(c1 == n || (c1 > 0 && c1 + c0 == n)){
		cout << "NO" << '\n';
		return;
	}

	if(c1 > 0 || c0 == n)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}