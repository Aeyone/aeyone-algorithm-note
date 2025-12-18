#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	priority_queue<int> q;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		q.push(x);
	}
	i64 a = 0, b = 0;
	for(int i = 0; i < n; i ++){
		int x = q.top();
		if(i & 1)
			b += x;
		else
			a += x;
		q.pop();
	}
	cout << a << ' ' << b << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}