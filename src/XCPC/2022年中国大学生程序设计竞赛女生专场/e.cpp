#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 1e5 + 10;
int a[N], b[2 * N], st[2 * N][20];

void solve() {
	int x, t, k, n, d;
	cin >> x >> t >> k >> n >> d;

	b[0] = x;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = b[i - 1] + (a[i] <= d ? -1 : 1);
	}

	if (b[n] < x || (b[n] == x && k == x && *max_element(b, b + n) <= k)) {
		cout << "YES" << '\n';
		return;
	}

	for (int i = 1; i <= n; i ++) {
		b[n + i] = (b[n + i - 1] + (a[i] <= d ? -1 : 1));
	}

	int m = 2 * n + 1;
	for (int i = 1; i < m; i ++) {
		st[i][0] = b[i];
	}
	for (int p = 1; m >> p > 0; p ++) {
		for (int i = 1; i + (1 << p) <= m; i ++) {
			st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->int {
		int d = __lg(r - l + 1);
		return max(st[l][d], st[r - (1 << d) + 1][d]);
	};

	bool ok = false;
	for (int i = 1; i + t - 1 < m; i ++) {
		ok |= (query(i, i + t - 1) <= k);
	}
	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
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