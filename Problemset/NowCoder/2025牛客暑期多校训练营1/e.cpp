#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<int> a;
	for(int i = 2; i <= 100; i ++){
		for(int j = 1; j < i; j ++)
			a.push_back(i * i - j * j);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for(auto e : a)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}