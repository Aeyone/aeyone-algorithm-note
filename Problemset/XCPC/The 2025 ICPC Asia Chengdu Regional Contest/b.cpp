#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

i64 g1[64][65], g2[64][64][65];

void solve() {
	memset(g1, -1, sizeof g1);
	memset(g2, -1, sizeof g2);
	i64 n, m, k, R;
	cin >> n >> m >> k >> R;
	vector<i64> a(n), c(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i] >> c[i];
	}
	g1[0][0] = 0;
	for(int rd = 1; rd <= 1 << n; rd ++){
		for(int st = 0; st < 1 << n; st ++){
			if(g1[st][rd - 1] == -1){
				continue;
			}
			for(int op = 0; op < 1 << n; op ++){
				i64 cost = 0, dg = 0;
				for(int i = 0; i < n; i ++){
					cost += c[i] * (op >> i & 1) + k * (st >> i & 1) * (op >> i & 1);
					dg += a[i] * (op >> i & 1);
				}
				if(cost <= m){
					g1[op][rd] = max(g1[op][rd], g1[st][rd - 1] + dg);
				}
			}
		}
	}
	i64 mx = 0;
	for(int i = 0; i < 1 << n; i ++){
		mx = max(mx, g1[i][min(64LL, R)]);
	}
	if(R <= 64){
		cout << mx << '\n';
	}else{
		for(int i = 0; i < 1 << n; i ++){
			g2[i][0] = 0;
		}
		for(int rd = 1; rd <= 1 << n; rd ++){
			for(int st = 0; st < 1 << n; st ++){
				if(g2[st][rd - 1] == -1){
					continue;
				}
				for(int op = 0; op < 1 << n; op ++){
					i64 cost = 0, dg = 0;
					for(int i = 0; i < n; i ++){
						cost += c[i] * (op >> i & 1) + k * (st >> i & 1) * (op >> i & 1);
						dg += a[i] * (op >> i & 1);
					}
					if(cost <= m){
						g2[op][rd] = max(g2[op][rd], g2[st][rd - 1] + dg);
					}
				}
			}
		}
		R -= 64;
		int cnt = R / 64, r = (R % 64);
		i64 ans = 0;
		for(int i = 0; i < 1 << n; i ++){
			ans = max(ans, g2[i][64] * cnt + g2[i][r] + mx);
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}