#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
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
	queue<array<int, 2>> q;
	vector<vector<int>> vis(n, vector<int>(m));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(g[i][j] == '#'){
				vis[i][j] = 4;
				continue;
			}
			for(int k = 0; k < 4; k ++){
				int x = i + dx[k], y = j + dy[k];
				if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '.'){
					continue;
				}
				vis[i][j] ++;
			}
			if(vis[i][j] == 1){
				q.push({i, j});
			}
		}
	}
	while(q.size()){
		int cnt = q.size();
		vector<array<int, 2>> alls;
		while(cnt --){
			auto [x, y] = q.front();
			q.pop();
			if(vis[x][y] != 1){
				continue;
			}
			alls.push_back({x, y});
		}
		for(auto [x, y] : alls){
			g[x][y] = '#';
			for(int i = 0; i < 4; i ++){
				int a = x + dx[i], b = y + dy[i];
				if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#'){
					continue;
				}
				vis[a][b] ++;
				q.push({a, b});
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++){
		ans += count(g[i].begin(), g[i].end(), '#');
	}
	cout << ans << '\n';
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