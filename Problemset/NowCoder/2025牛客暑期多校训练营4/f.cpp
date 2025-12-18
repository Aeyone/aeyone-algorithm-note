#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k, c;
	cin >> n >> k >> c;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	i64 cnt = 0, ans = 0;
	priority_queue<i64, vector<i64>, greater<i64>> h1;
	for(int i = k; i >= 1; i --){
		ans += a[i];
		a[i] += cnt * c, cnt ++;
		h1.push(a[i]);
	}
	cnt = 0;
	priority_queue<i64> h2;
	for(int i = k; i <= n; i ++){
		a[i] -= cnt * c, cnt ++;
		h2.push(a[i]);
	}
	i64 x = h2.top() - h1.top();
	while(x > 0){
		ans += x;
		h1.pop(), h2.pop();
		if(h1.size() && h2.size())
			x = h2.top() - h1.top();
		else
			break;
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