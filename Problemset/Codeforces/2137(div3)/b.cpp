#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for(int i = 0; i < n; i ++){
		cin >> p[i];
		q[i] = n + 1 - p[i];
	}
	for(auto e : q)
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