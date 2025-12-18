#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] ++;

	int ans = 0;
	for(int i = 1; i <= n; i ++){	
		int sum = 0;
		for(auto [num, c] : mp){
			sum += i * (c >= i);
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}