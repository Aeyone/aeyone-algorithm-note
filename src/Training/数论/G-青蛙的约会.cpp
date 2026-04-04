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
	int x, y, n, m, L;
	cin >> x >> y >> n >> m >> L;
	if (x > y) {
		swap(x, y);
		swap(n, m);
	}
	auto check = [&](int t)-> int {
		return (y + t * m) - (x + t * n);
	};

	int l = 0, r = min((L - x + 1) / n, (L - y + 1) / m), ans = 0;
	cout << "l, r = " << l << ' ' << r << '\n';
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) <= 0) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << "ans = " << ans << '\n';
	cout << "check(ans) = " << check(ans) << '\n';
	if (check(ans) != 0) {
		cout << "Impossible" << '\n';
	} else {
		cout << ans << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}