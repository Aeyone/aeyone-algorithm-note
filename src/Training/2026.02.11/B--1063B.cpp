#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	int r, c;
	cin >> r >> c;
	r --, c --;
	int cl, cr;
	cin >> cl >> cr;
	vector<string> g(n);
	for (auto &s : g) {
		cin >> s;
	}
	vector vis(n, vector<int>(m));
	deque<array<int, 4>> q;

	q.push_front({r, c, 0, 0});
	vis[r][c] = true;

	while (q.size()) {
		auto [x, y, tl, tr] = q.front();
		q.pop_front();

		for (int i = 0; i < 4; i ++) {
			int a = x + dx[i], b = y + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= m || vis[a][b] || g[a][b] == '*') {
				continue;
			}
			if (i < 2) {
				if (tl + (i == 1) > cl || tr + (i == 0) > cr) {
					continue;
				}
				q.push_back({a, b, tl + (i == 1), tr + (i == 0)});
				vis[a][b] = true;
			} else {
				q.push_front({a, b, tl, tr});
				vis[a][b] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		ans += count(vis[i].begin(), vis[i].end(), 1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}