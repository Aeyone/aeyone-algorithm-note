#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), ans(n + 1);
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	int mn = n;
	for(int l = 0, r = n - 1; l <= r; r --){
		sum -= a[r];
		while(sum > a[r]){
			ans[r - l + 1] = sum + a[r];
			mn = min(mn, r - l + 1);
			sum -= a[l ++];
		}
		while(l > 0 && r - l + 1 < mn && sum <= a[r]){
			sum += a[-- l];
		}
	}
	for(int i = 1; i <= n; i ++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}