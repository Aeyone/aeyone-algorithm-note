#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if(a >= n){
		cout << "Sayonara" << '\n';
		return;
	}
	if((n % (a + b)) > a || ((n % (a + b)) == 0))
		cout << 0 << '\n';
	else
		cout << (n % (a + b)) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}