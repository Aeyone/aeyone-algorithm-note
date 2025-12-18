#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 mx = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	auto work = [&](int mx)->i64{
		i64 c[3] = {}, hi = 0;
		for(auto e : a){
			e = mx - e;
			c[e % 3] ++;
			c[1] += e / 3, c[2] += e / 3;
			hi += e / 2;
		}
		while(c[2] - c[1] >= 2){
			c[2] --, c[1] += 2;
		}
		while(c[1] - c[2] >= 2 && c[2] < hi){
			c[2] ++, c[1] -= 2;
		}
		return max(c[1] * 2 - 1, c[2] * 2);
	};
	i64 ans = min({work(mx), work(mx + 1), work(mx + 2)});
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