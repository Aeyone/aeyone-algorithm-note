#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	m --;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<i64> pre(m + 1);
	pre[0] = a[0];
	for(int i = 1; i <= m; i ++){
		pre[i] = pre[i - 1] + a[i];
	}
	i64 mn = pre[m];
	int ans = 0;
	priority_queue<int> h1, h2;
	for(int i = m - 1; i >= 0; i --){
		if(a[i + 1] > 0)
			h1.push(a[i + 1]);

		mn = min(mn, pre[i]);
		if(mn == pre[m])
			continue;

		pre[m] -= 2 * h1.top();
		h1.pop();
		ans ++;
		mn = pre[m];
	}
	
	i64 cur = 0;
	for(int i = m + 1; i < n; i ++){
		cur += a[i];
		if(a[i] < 0){
			h2.push(-a[i]);
		}
		while(cur < 0){
			cur += 2 * h2.top();
			h2.pop();
			ans ++;
		}
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