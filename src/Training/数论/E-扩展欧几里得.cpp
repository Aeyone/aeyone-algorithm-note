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

int exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int X = x;
	x = y, y = X - (a / b) * y;
	return d;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = 0, y = 0;
	int g = exgcd(a, b, x, y);
	if (c % g != 0) {
		cout << -1 << '\n';
		return;
	}
	x *= (c / g), y *= (c / g);
	int tx = b / g, ty = a / g;

	int l = -1e9, r = 1e9, L = 0, R = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x + mid * tx > 0) {
			L = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	l = -1e9, r = 1e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (y - mid * ty > 0) {
			R = mid, l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	// cerr << "x, y = " << x << ' ' << y << '\n';
	// cerr << "tx, ty = " << tx << ' ' << ty << '\n';
	// cerr << "L, R = " << L << ' ' << R << '\n';
	cout << x + L * tx << ' ' << y - R * ty << ' ';
	if (L <= R) {
		cout << x + R * tx << ' ' << y - L * ty << ' ' << R - L + 1 << ' ';
	}
	cout << '\n';


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