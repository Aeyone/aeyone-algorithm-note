#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> a(n);
	priority_queue<int, vector<int>, greater<int>> heap;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	i64 sum = 0, ans = 0;
	for(int i = 0; i < n; i ++) if(a[i] > 0){
		if(heap.size() < m){
			heap.push(a[i]), sum += a[i];
			ans = max(ans, sum - (i64)d * (i + 1));
		}else if(a[i] > heap.top()){
			sum += a[i], sum -= heap.top();
			heap.push(a[i]), heap.pop();
			ans = max(ans, sum - (i64)d * (i + 1));
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