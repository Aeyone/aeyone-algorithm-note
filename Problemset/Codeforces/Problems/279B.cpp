#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	queue<int> q;
	int sum = 0, ans = 0;
	for(auto e : a){
		while(sum + e > k && q.size())
			sum -= q.front(), q.pop();
		
		if(e > k)
			continue;

		q.push(e), sum += e;
		ans = max(ans, (int)q.size());
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}