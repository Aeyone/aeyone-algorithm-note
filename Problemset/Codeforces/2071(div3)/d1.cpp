#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	i64 l, r;
	cin >> n >> l >> r;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	if(l <= n){
		cout << a[l] << '\n';
		return;
	}
	i64 m = l / 2;
	
	int res = 0;
	for(int i = 1; i <= n; i ++)
		res ^= a[i];

	//当n为偶数的时候会单独多出一个数
	if(!(n & 1)){
		for(int i = 1; i <= n / 2; i ++)
			res ^= a[i];
	}

	int cnt = 0;
	while(m > n && !(m & 1)){
		cnt ++, m >>= 1;
	}

	int ans = 0;
	if(m <= n){
		ans = ((cnt & 1) ? res : 0);
		for(int i = 1; i <= m; i ++)
			ans ^= a[i];
	}else{
		ans = (((cnt + 1) & 1) ? res : 0);
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