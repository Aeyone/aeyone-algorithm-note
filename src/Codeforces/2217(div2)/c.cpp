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

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int xa = 0, ya = 0, xb = 0, yb = 0;
	if (__gcd(a, n) != 1 || __gcd(b, m) != 1 || __gcd(n, m) > 2) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
	}
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