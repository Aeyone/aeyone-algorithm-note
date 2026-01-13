#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 x, y;
	cin >> x >> y;
	if(x < y)
		swap(x, y);

	int a = 0, b = 0;
	while(__builtin_clz(x) + (!x) < __builtin_clz(y) + (!y))
		x >>= 1, a ++;

	while(x != y){
		x >>= 1, y >>= 1;
		a ++, b ++;
	}
	priority_queue<int, vector<int>, greater<int>> heap;
	map<int, bool> vis;
	for(int i = 1; i <= 1000; i ++)
		heap.push(i);

	i64 ans = 0;
	while(a > 0 || b > 0){
		if(a < b)
			swap(a, b);
		while(vis[heap.top()])
			heap.pop();
		int x = heap.top();
		heap.pop();

			// cout << "a = " << a << '\n';
			// cout << "b = " << b << '\n';
			// cout << "x = " << x << '\n';
			// cout << "ans = " << ans << '\n';
			// cout << '\n';

		if(a - x > x)
			a -= x, ans += pow(2, x);
		else
			ans += pow(2, a), vis[a] = true, a = 0;
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