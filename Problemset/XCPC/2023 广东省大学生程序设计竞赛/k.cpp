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
	vector<vector<int>> g(n, vector<int>(m));
	for(int i = 0; i < k; i ++){
		int x, y;
		cin >> x >> y;
		x --, y --;
		g[x][y] = 1;
	}
	int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
	int ans = k;
	auto dfs = [&](auto &&self, int cnt)->int{
		int res = 0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				res += g[i][j];
			}
		}
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(!g[i][j]){
					continue;
				}
				for(int k = 0; k < 4; k ++){
					int a = i + dx[k], b = j + dy[k];
					if(a < 0 || a >= n || b < 0 || b >= m || !g[a][b]){
						continue;
					}
					if(a + dx[k] < 0 || a + dx[k] >= n || b + dy[k] < 0 || b + dy[k] >= m || g[a + dx[k]][b + dy[k]]){
						continue;
					}
					g[i][j] = g[a][b] = 0;
					g[a + dx[k]][b + dy[k]] = 1;
					res = min(res, self(self, cnt + 1));
					g[i][j] = g[a][b] = 1;
					g[a + dx[k]][b + dy[k]] = 0;
				}
			}
		}
		return res;
	};
	cout << dfs(dfs, 0) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}