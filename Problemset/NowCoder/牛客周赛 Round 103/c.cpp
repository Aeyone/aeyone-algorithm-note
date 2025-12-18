#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b, int p){
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
	int n;
	cin >> n;
	cout << qmi(2, n - 1, mod) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}