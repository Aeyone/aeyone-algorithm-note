#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto &[x, y] : a){
		cin >> x >> y;
	}
	map<array<int, 3>,int> mp;
	map<array<int, 2>,int> mp1;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			int dx = a[i][0] - a[j][0];
			int dy = a[i][1] - a[j][1];
			if(dy < 0 || (dy == 0 && dx < 0)){
				dx *= -1, dy *= -1;
			}
			int g = __gcd(abs(dx), abs(dy));
			mp[{dy / g, dx / g, dy * dy + dx * dx}] ++;
		}
	}
	int ans = 0, tot = 0;
	for(auto [_, c] : mp){
		tot += 1ll * c * (c - 1) / 2;
		auto [x, y, e] = _;
		mp1[{x, y}] += c;
	}
	for(auto [_, c] : mp1){
		ans += 1ll * c * (c - 1) / 2;
	}
	cout << ans - tot / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}