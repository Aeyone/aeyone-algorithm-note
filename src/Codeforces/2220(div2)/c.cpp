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
	int p, q;
	cin >> p >> q;
	auto run = [&](int q)-> pair<int, int> {
		int mn = INF, mx = 0;
		for (int i = 1; i <= q / i; i ++) {
			if (q % i == 0) {
				mx = max(mx, q / i + i);
				mn = min(mn, q / i + i);
			}
		}
		return {mx, mn};
	};

	int l = -1, r = p;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (run(q + mid).first )
	}

	if (m == -1 && n == -1) {
		cout << -1 << '\n';
	} else {
		cout << n << ' ' << m << '\n';
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