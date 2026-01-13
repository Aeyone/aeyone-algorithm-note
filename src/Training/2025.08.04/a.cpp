#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), lazy(n);
	priority_queue<array<int, 4>> heap;
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		lazy[i] = a[i];
		ans += a[i];
	}
	for(int i = 0; i < n; i ++){
		if(i - 1 >= 0)
			heap.push({a[i] - a[i - 1], -a[i - 1], i, i - 1});
		if(i + 1 < n)
			heap.push({a[i] - a[i + 1], -a[i + 1], i, i + 1});
	}	
	while(heap.size() && k > 0){
		auto [d, _, u, v] = heap.top();
		heap.pop();

		if(lazy[u] != a[u] || lazy[v] != a[v]){
			a[u] = lazy[u], a[v] = lazy[v];
			heap.push({a[u] - a[v], -a[v], u, v});
			continue;
		}
		if(d <= 0)
			break;
		ans -= d;
		lazy[u] = a[v];
		k --;
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