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
	int n, q;
	cin >> n >> q;
	vector<int> a(n), mx(n);
	vector<vector<int>> sum(n, vector<int> (2 * n + 1));
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			sum[i][a[j] + a[(j + i) % n]] ++;
		}
	}
	vector<int> ans(2 * n + 1);
	for (int i = 1; i <= 2 * n; i ++) {
		int mx = 0;
		for (int k = 0; k < n; k ++) {
			if (sum[k][i] > mx) {
				mx = sum[k][i];
				ans[i] = k;
			}
		}
	}
	while (q --) {
		int x;
		cin >> x;
		if (x > 2 * n) {
			cout << 0 << '\n';
		} else {
			cout << ans[x] << '\n';
		}
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