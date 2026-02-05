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
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int c;
	cin >> c;
	vector<int> a(8), b(8), base(10, 1), p(2027, 1);
	for (int i = 1; i <= 7; i ++) {
		cin >> a[i];
		b[i] = 1ll * (100 - a[i]) * qmi(100, MOD - 2, MOD) % MOD;
		a[i] = a[i] * qmi(100, MOD - 2, MOD) % MOD;
	}
	vector<set<int>> num(10);
	num[0] = {4};
	num[1] = {1, 2, 4, 5, 7};
	num[2] = {2, 6};
	num[3] = {2, 5};
	num[4] = {1, 5, 7};
	num[5] = {3, 5};
	num[6] = {3};
	num[7] = {2, 4, 5, 7};
	num[8] = {};
	num[9] = {5};
	for (int i = 0; i < 10; i ++) {
		for (int j = 1; j <= 7; j ++) {
			if (num[i].find(j) != num[i].end()) {
				base[i] = base[i] * b[j] % MOD;
			} else {
				base[i] = base[i] * a[j] % MOD;
			}
		}
	}
	for (int i = 0; i <= 2026; i ++) {
		int num = i;
		for (int j = 0; j < 4; j ++) {
			int cur = num % 10;
			p[i] = p[i] * base[cur] % MOD;
			num /= 10;
		}
	}
	int ans = 0;
	for (int i = 0; c - i >= 0; i ++) {
		ans = (ans + (p[i] % MOD * p[c - i] % MOD)) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}