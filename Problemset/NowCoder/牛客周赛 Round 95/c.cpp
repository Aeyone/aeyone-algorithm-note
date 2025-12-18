#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 d, p;
	cin >> d >> p;
	int q;
	cin >> q;
	i64 cnt = p / __gcd(d, p);
	while(q --){
		i64 l, r;
		cin >> l >> r;
        if(p == 1 && l == 1 && r > 1)
            cout << 2 << '\n';
        else
            cout << min(cnt, r - l + 1) << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}