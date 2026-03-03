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
	int n;
	cin >> n;
	vector<i64> a(n), d(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i ++) {
		d[i] = abs(a[i] - a[i - 1]);
	}
	vector st(n, vector<i64>(21));
	for (int i = 1; i < n; i ++) {
		st[i][0] = d[i];
	}
	for (int p = 1; p < 21; p ++) {
		for (int i = 1; i + (1 << p) <= n; i ++) {
			st[i][p] = __gcd(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->i64 {
		int d = __lg(r - l + 1);
		return __gcd(st[l][d], st[r - (1 << d) + 1][d]);
	};
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		int l = i, r = n - 1, tar = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(i, mid) >= 2) {
				tar = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (tar == i && d[i] == 1) {
			continue;
		}
		ans = max(ans, tar - i + 1);
	}
	cout << ans + 1 << '\n';
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