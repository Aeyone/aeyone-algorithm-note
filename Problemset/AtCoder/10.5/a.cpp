#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		cout << a[i] << ' ';
		if(i == k){
			cout << x << ' ';
		}
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}