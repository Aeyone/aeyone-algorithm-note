#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//枚举+二分 需要动点脑子
	int n, k;
	cin >> n >> k;
	vector<int> a(n), mn(n / 2), mx(n / 2);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	map<int, int> mp;
	for(int i = 0; i < n / 2; i ++){
		mn[i] = min(a[i], a[n - i - 1]);
		mx[i] = max(a[i], a[n - i - 1]);
		mp[a[i] + a[n - i - 1]] ++;
	}
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	int ans = INF;
	for(int x = 2; x <= 2 * k; x ++){
		int res = n / 2 - mp[x];
		res += lower_bound(mx.begin(), mx.end(), x - k) - mx.begin();
		res += n / 2 - (lower_bound(mn.begin(), mn.end(), x) - mn.begin());
		ans = min(ans, res);
		// cout << "res = " << res << '\n';
	}
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