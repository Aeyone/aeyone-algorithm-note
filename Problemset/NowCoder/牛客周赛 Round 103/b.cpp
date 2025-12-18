#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;
	int ok1 = 0, ok2 = 0;
	int idx1 = -1, idx2 = -1;
	for(int i = 0; i < n - 1; i ++){
		ok1 += (a[i] == 0 && a[i + 1] == 1);
		ok2 += (a[i] == 1 && a[i + 1] == 0);
	}
	if(ok1 > 1 || ok2 > 1)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}