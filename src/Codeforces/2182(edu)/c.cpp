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
	vector<int> a(2 * n), b(2 * n), c(2 * n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i ++) {
		a[i + n] = a[i];
		b[i + n] = b[i];
		c[i + n] = c[i];
	}
	vector<int> cntb(n, 1), bb(n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cntb[(j - i + n) % n] &= (a[i] < b[j]);
		}
	}
	for (int j = 0; j < n; j ++) {
		for (int i = 0; i < n; i ++) {
			bb[j] += cntb[(j - i + n) % n];
		}
	}
	vector<int> cntc(n, 1);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cntc[(j - i + n) % n] &= (b[i] < c[j]);
		}
	}
	i64 ans = 0;
	for (int j = 0; j < n; j ++) {
		for (int i = 0; i < n; i ++) {
			ans += cntc[(j - i + n) % n] * bb[i];
		}
	}
	cout << ans << '\n';
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