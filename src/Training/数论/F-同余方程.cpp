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
	int a, b;
	cin >> a >> b;
	int x = 0, y = 0;
	exgcd(a, b, x, y);
	int l = -1e9, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x + mid * b > 0) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << x + ans * b << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}