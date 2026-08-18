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
	int x, a, b;
	cin >> x >> a >> b;

	auto calc = [&](int k) -> i128 {
		auto check = [&](int A)-> i128 {
			i128 B = k - A;
			i128 m = A * a - A;
			i128 q = min(m, B);
			i128 cost = i128(A) * (a + A * a - A + 1) / 2 + B * b + q * (m + m - q + 1) / 2;
			return cost;
		};

		i128 l = 0, r = k, res = 0;
		while (r - l > 3) {
			i128 m1 = l + (r - l) / 3, m2 = l + 2 * (r - l) / 3;
			i128 a1 = check(m1), a2 = check(m2);
			if (a1 < a2) {
				l = m1;
			} else if (a1 > a2) {
				r = m2;
			} else {
				l = m1, r = m2;
			}
		}

		i128 ans = check(l);
		for (i128 i = l; i <= r; i ++) {
			ans = max(ans, check(i));
		}
		return ans;
	};

	int l = 1, r = INF, ans = r;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (calc(mid) >= x) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
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