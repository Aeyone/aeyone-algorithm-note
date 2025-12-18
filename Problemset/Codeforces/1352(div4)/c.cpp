#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k < n){
		cout << k << '\n';
		return;
	}
	int cnt = k / (n - 1);
	k -= cnt * (n - 1);
	if(k == 0)
		k += cnt * n - 1;
	else
		k += cnt * n;
	cout << k << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}