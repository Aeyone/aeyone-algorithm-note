#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int query(int x, int y) {
	cout << "? " << x << " " << y <<  endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 3; i <= 2 * n; i += 2) {
		if (query(i, i + 1)) {
			cout << "! " << i << endl;
			return;
		}
	}
	if (!query(1, 3) && ! query(1, 4)) {
		cout << "! " << 2 << endl;
	} else {
		cout << "! " << 1 << endl;
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