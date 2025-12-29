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
	int a, b;
	cin >> a >> b;
	int ans1 = 0, ans2 = 0;
	int A = a, B = b;
	while (A - (ans1 & 1) * (1 << ans1) >= 0 && B - (!(ans1 & 1)) * (1 << ans1) >= 0) {
		A -= (ans1 & 1) * (1 << ans1);
		B -= (!(ans1 & 1)) * (1 << ans1);
		ans1 ++;
	}
	A = a, B = b;
	while (A - (!(ans2 & 1)) * (1 << ans2) >= 0 && B - (ans2 & 1) * (1 << ans2) >= 0) {
		A -= (!(ans2 & 1)) * (1 << ans2);
		B -=  (ans2 & 1) * (1 << ans2);
		ans2 ++;
	}
	cout << max(ans1, ans2) << '\n';
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