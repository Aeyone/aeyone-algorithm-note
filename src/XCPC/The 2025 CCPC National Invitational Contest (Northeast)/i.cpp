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
	int n, s, t;
	cin >> n >> s >> t;
	if (s > t) {
		swap(s, t);
	}
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[a[i]] = i;
	}
	if (s == t) {
		cout << "Yes" << '\n';
		return;
	}
	if ((s <= n && t <= n) || (s > n && t > n)) {
		if (n >= 3) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	} else {
		if (a[s] == t) {
			cout << "No" << '\n';
		} else {
			cout << "Yes" << '\n';
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