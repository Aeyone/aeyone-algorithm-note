#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	i64 ans = 1ll * (c + 2) * (c + 1) / 2, odd = 0, even = 0;
	for(auto e : a){
		ans -= e / 2 + 1;
		ans -= c - e + 1;
		if(e & 1){
			odd ++;
			ans += odd;
		}else{
			even ++;
			ans += even;
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