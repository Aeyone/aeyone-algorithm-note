#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

i64 qmi(i64 a, i64 b){
	i64 res = 1;
	while(b){
		if(b & 1)
			res = (i64)a * res % mod;
		b >>= 1;
		a = (i64)a * a % mod;
	}
	return res;
}

i64 inv(i64 a, i64 b){
	return qmi(2, b * (mod - 2));
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<i64> sum = {0};
	int c2 = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] == 2)
			c2 ++;
		if(a[i] == 3)
			sum.push_back((sum.back() + qmi(2, c2) % mod) % mod);
	}
	int m = sum.size();
	c2 = 0;
	i64 c3 = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] == 2)
			c2 ++;
		if(a[i] == 3)
			c3 ++;
		if(a[i] != 1)
			continue;
		ans = (ans + ((i64)((sum[m - 1] - sum[c3] + mod) % mod) * inv(2, c2) % mod) % mod);
		ans = (ans - ((m - 1) - c3) + mod) % mod;
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