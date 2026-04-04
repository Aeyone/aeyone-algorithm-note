#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i64 phi(i64 x) {
	i64 res = x;
	for (int i = 2; i <= x / i; i ++) {
		if (x % i == 0) {
			res = res / i * (i - 1);
		}
		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1) {
		res = res / x * (x - 1);
	}
	return res;
}

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	string b;
	int a, m;
	cin >> a >> m >> b;

	auto M = [&](string s, int mod)-> i64 {
		i64 res = 0;
		for (auto e : s) {
			int u = e - '0';
			res = (res * 10 + u) % mod;
		}
		return res;
	};

	int pm = phi(m);
	if (__gcd(a, m) == 1) {
		cout << qmi(a, M(b, pm), m) << '\n';
	} else {
		string s = to_string(pm);
		bool ok = (s.size() > b.size() || (s.size() == b.size() && s > b));
		cout << qmi(a, M(b, pm) + (ok ? 0 : pm), m) << '\n';
	}


}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}