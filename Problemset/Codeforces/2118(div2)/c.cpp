#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n), bits(61);
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		for(int j = 0; j <= 60; j ++){
			if((a[i] >> j) & 1){
				// cout << a[i] << ' ' << j << '\n';
				ans ++;
				continue;
			}
			bits[j] ++;
		}
	}
	for(int i = 0; i <= 60; i ++){
		i64 cost = bits[i] * (1ll << i);
		if(k - cost >= 0){
			k -= cost;
			ans += bits[i];
		}else{
			ans += k / (1ll << i);
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}