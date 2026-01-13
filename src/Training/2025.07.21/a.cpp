#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	priority_queue<i64, vector<i64>, greater<i64>> heap;
	i64 sum = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		sum += (a[i] - d);
		heap.push(a[i]);
		if(heap.size() > m || heap.top() < 0){
			sum -= heap.top();
			heap.pop();
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}