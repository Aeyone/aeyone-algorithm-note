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
	int n, X, Y;
	cin >> n >> X >> Y;
	vector<string> g(3);
	cin >> g[1];
	cin >> g[2];
	X --, Y --;
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};//u, d, l, r

	vector<vector<int>> vis(4, vector<int>(n, -1));
	auto dfs = [&](auto &&self, int x, int y, int c)->bool{
		if(x == 0 || x == 3){
			return (x == 3 && y == Y);
		}
		int cur = vis[x][y];
		bool ok = false;
		if(g[x][y] == 'I'){
			int a = x + dx[cur], b = y + dy[cur];
			if(b >= 0 && b < n){
				vis[a][b] = cur;
				ok |= self(self, a, b, c);
				vis[a][b] = -1;
			}
		}
		if(g[x][y] == 'L'){
			if(cur == 2 || cur == 3){
				for(int i = 0; i < 2; i ++){
					vis[x + dx[i]][y] = 1;
					ok |= self(self, x + dx[i], y, c);
					vis[x + dx[i]][y] = -1;
				}
			}
			if(cur == 0 || cur == 1){
				if(c == 0 && y + 1 < n){//c == 0代表需要向右走
					vis[x][y + 1] = 3;
					ok |= self(self, x, y + 1, c);
					vis[x][y + 1] = -1;
				}
				if(c == 1 && y - 1 >= 0){//c == 1代表需要向左走
					vis[x][y - 1] = 2;
					ok |= self(self, x, y - 1, c);
					vis[x][y - 1] = -1;
				}
			}
		}
		return ok;
	};
	bool ok = false;
	if(g[1][X] == 'I'){
		vis[1][X] = 1;
		vis[2][X] = 1;
		ok |= dfs(dfs, 2, X, (X > Y));
		vis[1][X] = -1;
		vis[2][X] = -1;
	}
	if(g[1][X] == 'L'){
		vis[1][X] = 1;
		if(X - 1 >= 0){//左
			vis[1][X - 1] = 2;
			ok |= dfs(dfs, 1, X - 1, 1);
			vis[1][X - 1] = -1;
		}
		if(X + 1 < n){//右
			vis[1][X + 1] = 3;
			ok |= dfs(dfs, 1, X + 1, 0);
			vis[1][X + 1] = -1;
		}
		vis[1][X] = -1;
	}
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}