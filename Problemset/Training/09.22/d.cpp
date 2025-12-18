#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {//很好玩的二进制题
	i64 n, x;
	cin >> n >> x;
	i64 cur = n;
	bool ok = true;
	i64 l = 0, r = inf;
	for(int i = 61; i >= 0; i --){
		int tmp = 2 * (n >> i & 1) + (x >> i & 1);
		if(tmp == 2){
			l = max(l, (1ll << (i + 1)) - cur);
		}
		if(tmp == 3){
			r = min(r, (1ll << (i + 1)) - cur - 1);
		}
		cur -= (1ll << i) * (n >> i & 1);
		ok &= (tmp != 1 && l <= r);
	}
	if(ok){
		cout << n + l << '\n';
	}else{
		cout << -1 << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}