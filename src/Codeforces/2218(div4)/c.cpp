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
	vector<int> a(3 * n + 1);
	for (int i = 1; i <= 3 * n; i += 3) {
		a[i] = (i / 3 + 1);
		a[i + 1] = 2 * (i / 3 + 1) + n - 1;
		a[i + 2] = 2 * (i / 3 + 1) + n;
	}
	for (int i = 1; i <= 3 * n; i ++) {
		cout << a[i] << ' ';
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