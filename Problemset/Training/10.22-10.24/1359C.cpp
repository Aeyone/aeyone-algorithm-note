#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//三分，比较板
	i64 h, c, t;
	cin >> h >> c >> t;
	if(h + c >= t * 2){//min
		cout << 2 << '\n';
		return;
	}
	i64 l = 1, r = INF;
	while(r - l >= 3){
		i64 m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
		i64 a1 = abs(m1 * (h + c) - c - (m1 * 2 - 1) * t);
		i64 a2 = abs(m2 * (h + c) - c - (m2 * 2 - 1) * t);
		if(a1 > a2){
			l = m1;
		}else if(a1 < a2){
			r = m2;
		}else{
			l = m1, r = m2;
		}
	}
	i64 ans = 0, num = INF;
	for(i64 i = l; i <= r; i ++){
		i64 x = abs(i * (h + c) - c - t * (i * 2 - 1));
		if((i * 2 - 1) * num > (ans * 2 - 1) * x){
			num = x;
			ans = i;
		}
	}
	cout << ans * 2 - 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}