#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> low;
	for(int i = 0; (n >> i) >= 0 && i <= k; i ++){
		low.push_back(n >> i);
		// cout << (n >> i) << '\n';
		if((n >> i) == 0)
			break;
	}

	i64 ans = (k > 1 ? k : 0) + low.size();
	for(int i = 0; i < low.size(); i ++){
		int cnt = k - i - 1;
		if(low[i] == 1 || cnt <= 0)
			break;
		if(low[i] & 1)
			ans += cnt;
		// cout << low[i] << "!!!\n";
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _;
	cin >> _;
	while (_ --)
		solve();
}