#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x3f3f3f3f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	array<int, 2> st, ed;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(g[i][j] == 'S'){
				st = {i, j};
				g[i][j] = '.';
			}
			if(g[i][j] == 'G'){
				ed = {i, j};
				g[i][j] = '.';
			}
		}
	}
	int dis[2][n][m] {};
	memset(dis, 0x3f, sizeof dis);
	queue<array<int, 3>> q;

	dis[0][st[0]][st[1]] = 0;
	q.push({0, st[0], st[1]});
	while(q.size()){
		auto [t, x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || n <= a || b < 0 || m <= b){
				continue;
			}
			if(g[a][b] != '.' && g[a][b] != '?' && ((g[a][b] == 'x') ^ t || (g[a][b] == 'o' ^ (!t)))){
				continue;
			}
			int to = t;
			if(g[a][b] == '?'){
				to = !t;
			}
			if(dis[to][a][b] > dis[t][x][y] + 1){
				dis[to][a][b] = dis[t][x][y] + 1;
				q.push({to, a, b});
			}
		}
	}
	int ans = min(dis[0][ed[0]][ed[1]], dis[1][ed[0]][ed[1]]);
	cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}