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

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> a[i][j];
		}
	}
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	queue<array<int, 3>> q;
	vector<vector<int>> vis(n, vector<int>(m));
	q.push({0, 0, 0});
	q.push({n - 1, m - 1, 1});
	vis[0][0] = true;
	vis[n - 1][m - 1] = true;
	int ans = 0;
	while(q.size()){
		int cnt = q.size();
		int tot[2] = {};
		int ok1 = false, ok2 = false;
		while(cnt --){
			auto [x, y, sign] = q.front();
			q.pop();
			ok1 |= (sign == 0);
			ok2 |= (sign == 1);
			tot[a[x][y]] ++;
			for(int i = 0; i < 4; i ++){
				int a = x + dx[i], b = y + dy[i];
				if(a < 0 || a >= n || b < 0 || b >= m || vis[a][b]){
					continue;
				}
				q.push({a, b, sign});
				vis[a][b] = true;
			}
		}
		if(ok1 && ok2){
			ans += min(tot[0], tot[1]);
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