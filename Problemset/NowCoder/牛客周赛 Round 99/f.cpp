#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, m;
	cin >> n >> m;
	i64 x = n / m, r = n % m;

	i64 cnt = 0;
	while((x >> cnt) & 1)
		cnt ++;
	
	while(cnt && r){
		r %= (1ll << cnt);
		if(r)
			cnt --;
	}
	if(r || cnt)
		x &= (x + (1ll << cnt));
	cout << x << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}