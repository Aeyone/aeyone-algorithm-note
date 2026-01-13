#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

i64 qmi(int a, int b, int p){
	int res = 1;
	while(b){
		if(b & 1)
			res = (i64)a * res % p;
		b >>= 1;
		a = (i64)a * a % p;
	}
	return res;
}

void solve() {
	int l, r, k;
	cin >> l >> r >> k;
	int cnt = 0;
	while(cnt * k < 10)
		cnt ++;
	cout << (qmi(cnt, r, mod) - qmi(cnt, l, mod) + mod) % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}