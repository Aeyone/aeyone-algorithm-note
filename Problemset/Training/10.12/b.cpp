#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//粪
	i64 x, y, ca, cb, a, b;
	cin >> x >> y >> ca >> cb >> a >> b;
	if(a > b){
		swap(a, b), swap(ca, cb);
	}
	int ans = 0;
	for(int i = 0; i <= min(ca, x / a); i ++){
		int c1 = min(cb, (x - a * i) / b);
		int c2 = min(ca - i, y / a);
		int c3 = min(cb - c1, (y - a * c2) / b);
		ans = max(ans, i + c1 + c2 + c3);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}