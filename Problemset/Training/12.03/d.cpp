#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int x, y;
	cin >> x >> y;
	i64 ans = 0;
	int b = 2;
	while(b <= min(x - 1, y) && x / (b + 1) >= b - 1){
		ans += (b - 1);
		b ++;
	}
	for(int l = b + 1; l <= x; l ++){
		int num = x / l, r = x / num;
		if(r > y + 1){
			ans += 1ll * ((y + 1) - l + 1) * num;
			break;
		}else{
			ans += 1ll * (r - l + 1) * num;
			l = r;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}