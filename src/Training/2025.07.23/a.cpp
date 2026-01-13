#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int r;
	cin >> r;
	i64 x = 1, ans = 0;
	for(i64 i = r; i > 0; i --){
		for(; x <= r; x ++){
			double d = sqrt(x * x + i * i);
			if(d < r + 1 && d >= r)
				ans ++;
			else if(d >= r + 1)
				break;
		}
		x --;
	}
	cout << ans * 4 + 4 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}