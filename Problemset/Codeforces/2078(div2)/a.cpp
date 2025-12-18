#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], sum += a[i];
	if(sum % n == 0 && sum / n == x)
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