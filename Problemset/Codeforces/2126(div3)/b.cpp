#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int sign = a[0], d = 0;
	vector<pair<int, int>> b;
	for(int i = 0; i < n; i ++){
		if(sign == a[i])
			d ++;
		else
			b.push_back({sign, d}), sign = a[i], d = 1;
	}
	b.push_back({sign, d});
	int ans = 0;
	for(auto [e, len] : b){
		if(e == 0 && len >= k){
			int x = len;
			while(x > 0){
				x -= k;
				if(x >= 0)
					ans ++, x --;
			}
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