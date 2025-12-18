#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> mp(n);
	for(int i = 0; i < n; i ++)
		cin >> mp[i];

	vector<pii> g, b;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++){
			if(mp[i][j] == 'G')
				g.push_back({i, j});
			if(mp[i][j] == 'B')
				b.push_back({i, j});
		}

	for(auto [x, y] : b){
		for(int i = 0; i < 4; i ++){
			int xx = x + dx[i], yy = y + dy[i];
			if(xx < 0 || yy < 0 || n <= xx || yy >= m || mp[xx][yy] == 'B')
				continue;
			if(mp[xx][yy] == 'G'){
				cout << "No" << '\n';
				return;
			}
			mp[xx][yy] = '#';
		}
	}

	vector<vector<bool>> vis(n, vector<bool>(m, false));
	auto bfs = [&](int x, int y)->void{
		queue<pii> q, qq;
		q.push({x, y});
		vis[x][y] = true;
		while(q.size()){
			auto now = q.front();
			qq.push(now);
			q.pop();
			for(int i = 0; i < 4; i ++){
				int xx = now.first + dx[i], yy = now.second + dy[i];
				if(xx < 0 || yy < 0 || n <= xx || yy >= m || mp[xx][yy] == '#' || vis[xx][yy])
					continue;				
				q.push({xx, yy});
				vis[xx][yy] = true;
			}
		}
	};

	bool ok = true;
	if(mp[n - 1][m - 1] != '#')
		bfs(n - 1, m - 1);
	
	for(auto [x, y] : g)
		ok &= vis[x][y];

	if(mp[n - 1][m - 1] == 'B')
		ok = false;

	if(ok)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}