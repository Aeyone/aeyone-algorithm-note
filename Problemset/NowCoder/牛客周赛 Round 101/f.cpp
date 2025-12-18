#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 qmi(i64 a, i64 b, i64 p){
	i64 res = 1;
	while(b){
		if(b & 1)
			res = a * res % p;
		b >>= 1;
		a = a * a % p;
	}
	return res;
}

void solve() {
	i64 base, c0, mod;
	cin >> base >> c0 >> mod;
	int q;
	cin >> q;
	if(mod == 1){
		while(q --){
			i64 k;
			cin >> k;
			cout << 0 << '\n';
		}
		return;
	}
	vector<i64> a(2 * mod);
	map<i64, int> mp;
	int u = 1, st = 1;
	a[0] = c0;
	while(1){
		a[u] = qmi((base % mod), a[u - 1], mod);
        
		if(mp.find(a[u]) == mp.end())
			mp[a[u]] = u;
		else{
			st = mp[a[u]];
			break;
		}
		u ++;
	}
	vector<i64> s(2 * mod);
	for(int i = 1; i < u; i ++)
		s[i] = (s[i - 1] + a[i]) % mod;

	int len = u - st;
	i64 sum = (s[u - 1] - s[st - 1] + mod) % mod;

	while(q --){
		i64 k;
		cin >> k;
		if(k < u)
			cout << s[k] % mod << '\n';
		else{
			i64 siz = k - st + 1;
			i64 cnt = (siz / len) % mod;
			int r = (siz % len) + st - 1;

			i64 ans = (s[r] + (cnt * sum % mod)) % mod;
			cout << ans << '\n';
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}