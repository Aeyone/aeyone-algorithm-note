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
	auto check = [&](int x)->bool{
		bool ok = true;
		for (int l = 0, r = 0; x >> l > 0; l = r) {
			while ((x >> r & 1) == (x >> l & 1)) {
				r ++;
			}
			ok &= (r - l >= 2);
		}
		return ok;
	};
	int ans = 0;
	for (int i = a; i <= b; i ++) {
		ans += check(i);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}