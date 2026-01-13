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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(m, { -1, n}), b(n, {-1, m});
	for (int i = 0; i < k; i ++) {
		int x, y;
		cin >> x >> y;
		x --, y --;
		a[y].push_back(x);
		b[x].push_back(y);
	}
	for (auto &e : a) {
		sort(e.begin(), e.end());
	}
	for (auto &e : b) {
		sort(e.begin(), e.end());
	}
	vector<int> ck = {0};
	auto f = [&](vector<vector<int>> &a, int n)->bool{
		vector<vector<array<int, 2>>> seg(n);
		for (int y = 0; y < n; y ++) {
			for (int i = 1; i < a[y].size(); i ++) {
				int l = a[y][i - 1] + 1, r = a[y][i] - 1;
				if (l <= r) {
					seg[y].push_back({l, r});
				}
			}
		}
		vector<vector<int>> vis(n);
		for (int y = 0; y < n; y ++) {
			vis[y].assign(seg[y].size(), 0);
		}
		for (int i = 0, idx = 0; idx < ck.size() && i < seg[0].size(); i ++) {
			while(idx < ck.size() && ck[idx] <= seg[0][i][1]) {
				vis[0][i] |= (ck[idx] >= seg[0][i][0]);
				idx ++;
			}
		}
		for (int y = 1; y < n; y ++) {
			for (int i = 0, j = 0; i < seg[y - 1].size() && j < seg[y].size(); ) {
				if (!vis[y - 1][i] || seg[y][j][0] > seg[y - 1][i][1]) {
					i ++;
					continue;
				}
				if (seg[y][j][1] < seg[y - 1][i][0]) {
					j ++;
					continue;
				}
				while (j < seg[y].size() && seg[y][j][1] >= seg[y - 1][i][0] && seg[y][j][0] <= seg[y - 1][i][1]) {
					vis[y][j ++] = true;
				}
			}
			if (vis[y].size() && vis[y][0] && seg[y][0][0] == 0) {
				ck.push_back(y);
			}
		}
		return vis[n - 1].back();
	};
	if (f(a, m) || f(b, n)) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
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