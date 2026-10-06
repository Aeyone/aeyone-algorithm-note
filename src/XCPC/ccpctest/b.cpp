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

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
		res = a * res % p;
	}
	return res;
}

void solve() {
	int p, y, b, ab;
	cin >> p >> y;
	cout << "? 0" << endl;
	cin >> b;
	cout << "? 1" << endl;
	cin >> ab;
	int a = (ab - b + p) % p;
	cout << "! ";
	cout << ((y - b + p) % p) * qmi(a, p - 2, p) % p << '\n';
}

signed main() {
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}