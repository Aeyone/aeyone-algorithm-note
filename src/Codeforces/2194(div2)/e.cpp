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

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	int n, m;
	cin >> n >> m;
	vector a(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	vector dp1(n + 1, vector<int>(m + 1, -INFLL));
	dp1[1][1] = a[1][1];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (i + 1 <= n) {
				cmax(dp1[i + 1][j], dp1[i][j] + a[i + 1][j]);
			}
			if (j + 1 <= m) {
				cmax(dp1[i][j + 1], dp1[i][j] + a[i][j + 1]);
			}
		}
	}
	vector dp2(n + 1, vector<int>(m + 1, -INFLL));
	dp2[n][m] = a[n][m];
	for (int i = n; i >= 1; i --) {
		for (int j = m; j >= 1; j --) {
			if (i - 1 >= 1) {
				cmax(dp2[i - 1][j], dp2[i][j] + a[i - 1][j]);
			}
			if (j - 1 >= 1) {
				cmax(dp2[i][j - 1], dp2[i][j] + a[i][j - 1]);
			}
		}
	}
	
	using T = array<int, 3>;
	vector<set<T>> mx(n + m + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int b = i + j - 1;
			mx[b].insert({dp1[i][j] + dp2[i][j] - a[i][j], i, j});
			if (mx[b].size() > 2) {
				mx[b].erase(mx[b].begin());
			}
		}
	}

	int ans = INFLL;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i][j] < 0) {
				continue;
			}
			int res = dp1[i][j] + dp2[i][j] - a[i][j] * 3; // 经过i,j
			if (mx[i + j - 1].size() == 2) {
				auto [e1, _i, _j] = *mx[i + j - 1].begin();
				auto [e2, __i, __j] = *(--mx[i + j - 1].end());
				if (i == __i && j == __j) {
					res = max(res, e1);
				} else {
					res = max(res, e2);
				}
			}
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
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