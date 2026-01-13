#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	i64 ans = -1e16;
	if(n <= 1000){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				if(i == j)
					continue;
				ans = max(ans, (i64)(i + 1) * (j + 1) - k * (a[i] | a[j]));
			}
		}
	}else{
		for(int i = n - 1; i >= max(0ll, n - 1000); i --){
			for(int j = n - 1; j >= max(0ll, n - 1000); j --){
				if(i == j)
					continue;
				ans = max(ans, (i64)(i + 1) * (j + 1) - k * (a[i] | a[j]));
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