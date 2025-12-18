#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i = 0; i < n - 1; i ++)
		cin >> d[i];
	for(int i = 0; i < n - 1; i ++){
		i64 res = 0;
		for(int j = i; j < n - 1; j ++){
			res += d[j];
			cout << res << ' ';
		}
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}