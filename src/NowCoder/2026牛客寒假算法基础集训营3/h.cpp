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
	double a[2] = {}, b[2] = {};
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];

	if (a[1] == b[1]) {
		if (abs(a[0] - b[0]) * abs(a[1]) != 4) {
			cout << "no answer" << '\n';
		} else {
			cout << 0 << '\n';
		}
	} else {
		cout << (a[1] * b[0] - a[0] * b[1] + 4) / (a[1] - b[1]) << '\n';
	}

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