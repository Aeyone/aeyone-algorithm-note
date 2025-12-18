/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector<vector<int>> g(2 * n + 1, vector<int>(2 * m + 1));
	array<int, 2> p1 = {n + 1, m + 1}, p2 = {2 * n, 2 * m};
	int x = n + 1, y = m + 1;
	g[x][y] = true;
	for(auto e : s){
		x += (e == 'U');
		x -=(e == 'D');
		y += (e == 'L');
		y -=(e == 'R');
		if(x <= 2 * n && y <= 2 * m && x > 0 && y > 0){
			g[x][y] = true;
		}
		p1[0] = max(p1[0], x);
		p1[1] = max(p1[1], y);
		p2[0] = min(p2[0], 2 * n + (x - n - 1));
		p2[1] = min(p2[1], 2 * m + (y - m - 1));
	}
	vector<vector<int>> pre(2 * n + 1, vector<int>(2 * m + 1));
	for(int i = 1; i <= 2 * n; i ++){
		for(int j = 1; j <= 2 * m; j ++){
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + g[i][j];
		}
	}

	if(p1[0] > p2[0] || p1[1] > p2[1]){
		cout << (k == 0 ? n * m : 0) << '\n';
		return;
	}
	int R = n * m - (p2[0] - p1[0] + 1) * (p2[1] - p1[1] + 1);
	int ans = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			auto [x1, y1] = p1;
			auto [x2, y2] = p2;
			x1 -= i, x2 -= i;
			y1 -= j, y2 -= j;
			int cnt = pre[x2][y2] - pre[x2][y1 - 1] -  pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
			ans += (R + cnt == n * m - k);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}