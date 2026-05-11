#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 1e3;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i];
	}

	vector<vector<int>> pre(n + 1, vector<int>(N + 1)), suf(n + 2, vector<int>(N + 1));

	for (int i = 1; i <= n; i ++) {
		for (int j = N; j >= 0; j --) {
			pre[i][j] = pre[i - 1][j];
			if (j >= a[i]) {
				pre[i][j] = max(pre[i][j], pre[i - 1][j - a[i]] + b[i]);
			}
		}
	}

	for (int i = n; i >= 1; i --) {
		for (int j = N; j >= 0; j --) {
			suf[i][j] = suf[i + 1][j];
			if (j >= a[i]) {
				suf[i][j] = max(suf[i][j], suf[i + 1][j - a[i]] + b[i]);
			}
		}
	}

	int q;
	cin >> q;
	while (q --) {
		int d, e;
		cin >> d >> e;
		d ++;
		
		int ans = 0, p = 0, s = 0;
		for (int i = 0; i <= e; i ++) {
			p = max(p, pre[d - 1][i]);
			s = suf[d + 1][e - i];
			ans = max(ans, p + s);
		}

		cout << ans << '\n';
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