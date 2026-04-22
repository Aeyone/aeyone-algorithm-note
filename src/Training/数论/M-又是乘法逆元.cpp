#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1000000007;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> pre(n + 1), suf(n + 2);
	pre[0] = suf[n + 1] = 1;
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] * a[i] % MOD;
	}
	for (int i = n; i >= 1; i --) {
		suf[i] = suf[i + 1] * a[i] % MOD;
	}

	int cur = 1, ans = 0;
	for (int i = n; i >= 1; i --) {
		ans = (ans + cur * pre[i - 1] % MOD * suf[i + 1] % MOD) % MOD;
		cur = cur * 998244353 % MOD;
	}
	ans = ans * qmi(pre[n], MOD - 2) % MOD;
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}