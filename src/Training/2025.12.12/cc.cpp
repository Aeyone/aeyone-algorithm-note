#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	i64 n, k;
	cin >> n >> k;
	i64 ans = 0;
	for(int i = 0; i <= n; i ++) {
		ans = (ans + 1ll * i * (__builtin_popcountll(i) == k) % MOD) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}