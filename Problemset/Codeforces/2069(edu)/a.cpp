#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	n -= 2;
	vector<int> b(n);
	for(int i = 0; i < n; i ++)
		cin >> b[i];
	bool ok = false;
	for(int i = 1; i < n - 1; i ++)
		ok |= (b[i] == 0 && b[i - 1] == 1 && b[i + 1] == 1);
	if(!ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}