#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	i64 a, b;
	cin >> a >> b;
	auto dfs = [&](auto &&self, i64 a, i64 b, int cnt)->int{
		if(min(a, b) <= 0){
			return 1;
		}
		if(cnt > 13){
			return INF;
		}
		int res = 0;
		i64 g = __gcd(a, b);
		if(g > 1){
			res = self(self, a / g, b / g, cnt);
		}else{
			int r1 = INF, r2 = INF, r3 = INF;
			r1 = self(self, a - 1, b, cnt + 1) + 1;
			r2 = self(self, a, b - 1, cnt + 1) + 1;
			if((a - 1) % 2 == 0 && (b - 1) % 2 == 0){
				r3 = self(self, a - 1, b - 1, cnt + 1) + 2;
			}
			res = min({r1, r2, r3});
		}
		return res;
	};
	cout << dfs(dfs, a, b, 0) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}