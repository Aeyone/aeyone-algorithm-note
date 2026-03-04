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
	vector<int> a(1 << n);
	for (int i = 0; i < 1 << n; i ++) {
		cin >> a[i];
	}
	vector p(1 << n, vector<double>(n + 1));

	auto calc = [&](int i, int j)->double {
		return 1.0 / (1 + pow(10, double(a[j] - a[i]) / 400));
	};
	auto dfs = [&](this auto &&self, int cur, int l, int r)->void {
		if (cur == 0) {
			p[l][cur] = 1.0;
			return;
		}
		int mid = l + r >> 1;
		self(cur - 1, l, mid);
		self(cur - 1, mid + 1, r);

		for (int i = l; i <= mid; i ++) {
			for (int j = mid + 1; j <= r; j ++) {
				p[i][cur] += calc(i, j) * p[i][cur - 1] * p[j][cur - 1];
				p[j][cur] += calc(j, i) * p[i][cur - 1] * p[j][cur - 1];
			}
		}
	};
	dfs(n, 0, (1 << n) - 1);
	for (int i = 0; i < 1 << n; i ++) {
		cout << p[i][n] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(9);
	int _ = 1;
	while (_ --) {
		solve();
	}
}