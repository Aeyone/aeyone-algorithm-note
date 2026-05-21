#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	i64 n, x;
	cin >> n >> x;
	if ((x ^ 1) > n) {
		cout << 0 << '\n';
		return;
	}
	if (!(n & 1)) n --;
	i64 pre[2] {}, suf[2] {};

	i64 pre_cnt = x / 2, suf_cnt = n / 2 - x / 2;

	pre[0] = (pre_cnt + 1) / 2 % MOD;
	pre[1] = (1 + pre_cnt / 2) % MOD;

	suf[0] = (suf_cnt + 1) / 2 % MOD;
	suf[1] = (1 + suf_cnt / 2) % MOD;

	cout << (pre[0] * suf[1] % MOD + pre[1] * suf[0] % MOD) % MOD << '\n';
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