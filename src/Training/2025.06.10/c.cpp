#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int cnt = 0;
	if(n == (n & - n)){
		int x = n;
		while(x > 1)
			x /= 2, cnt ++;
	}
	if(n & 1 || cnt & 1)
		cout << "Bob" << '\n';
	else
		cout << "Alice" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}