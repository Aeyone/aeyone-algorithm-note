#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 qmi(i128 a, i128 b, i64 p = MOD) {
	i128 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
		res = a * res % p;
	}
	return res;
}

void solve() {
	i64 n, m, l;
	cin >> n >> m >> l;
	i64 inv = (n + 2) / 2;
	cout << i64((i128(l) * qmi(inv, m, n + 1)) % (n + 1)) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}