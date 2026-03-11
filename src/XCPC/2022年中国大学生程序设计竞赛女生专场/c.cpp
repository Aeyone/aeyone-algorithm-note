#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const double pi = acos(-1);

void solve() {
	int n;
	double R, apha;
	cin >> n >> R >> apha;
	apha = min(pi * 2 - apha, apha);
	double ans = min(2 * R, apha * R);
	for (int i = 0; i < n; i ++) {
		double r;
		cin >> r;
		ans = min(ans, (R - r) * 2 + apha * r);
	}
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