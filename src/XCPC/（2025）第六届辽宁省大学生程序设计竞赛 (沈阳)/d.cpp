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
	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 3; j ++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> op = {{0}, {1}, {2}, {0, 1}, {1, 2}, {0, 2}, {0, 1, 2}};
	for (auto v : op) {
		bool ok = true;
		for (int i = 0; i < n; i ++) {
			bool ok1 = false;
			for (auto idx : v) {
				ok1 |= a[i][idx];
			}
			ok &= ok1;
		}
		if (ok) {
			cout << v.size() << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}