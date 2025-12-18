#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	int x = 0;
	for(int i = 0; i < 4; i ++)
		x += (s[i] - '0'), x *= 10;
	x /= 10;
	// cout << x << endl;
	bool ok = false;
	for(int a = 0; a < 100; a ++)
		for(int b = 0; b < 100; b ++){
			ok |= ((a + b) * (a + b) == x);
			if(ok){
				cout << a << " " << b << '\n';
				return;
			}
		}
	cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}