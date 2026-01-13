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
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	i64 sum = 0;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		sum += x;
	}
	int c0 = count(s.begin(), s.end(), '0');
	int c1 = count(s.begin(), s.end(), '1');
	if (sum > x + y) {
		cout << "NO" << '\n';
		return;
	}
	if (c0 && c1) {
		if (x - c0 >= 0 && y - c1 >= 0) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} else if (c0) {
		if (x > y) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} else if (c1) {
		if (y > x) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
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