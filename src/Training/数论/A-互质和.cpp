#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

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

void solve() {
	i64 n;
	cin >> n;
	if (n <= 2) {
		cout << 1 << '\n';
		return;
	}
	cout << (phi(n) / 2) % MOD * (n % MOD) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}