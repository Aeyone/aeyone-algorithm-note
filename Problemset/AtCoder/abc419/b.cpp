#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int q;
	cin >> q;
	priority_queue<int, vector<int>, greater<int>> heap;
	while(q --){
		int sign;
		cin >> sign;
		if(sign == 1){
			int x;
			cin >> x;
			heap.push(x);
		}
		if(sign == 2){
			cout << heap.top() << '\n';
			heap.pop();
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}