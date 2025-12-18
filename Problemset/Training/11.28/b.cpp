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
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; //-> V <- ^

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	vector<vector<array<int, 4>>> dis(n, vector<array<int, 4>>(m, {INF, INF, INF, INF}));
	deque<array<int, 4>> q;//[x, y, w, op]

	q.push_front({0, 0, 0, 0});
	dis[0][0][0] = 0;
	int ans = INF;
	while(q.size()){
		auto [x, y, w, op] = q.front();
		q.pop_front();
		
		int a, b;
		if(g[x][y] == 'A'){
			a = x + dx[op], b = y + dy[op];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op] > w){
				dis[a][b][op] = w;
				q.push_front({a, b, w, op});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w);
			}

			a = x + dx[op ^ 1], b = y + dy[op ^ 1];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 1] > w + 1){
				dis[a][b][op ^ 1] = w + 1;
				q.push_back({a, b, w + 1, op ^ 1});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}

			a = x + dx[op ^ 3], b = y + dy[op ^ 3];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 3] > w + 1){
				dis[a][b][op ^ 3] = w + 1;
				q.push_back({a, b, w + 1, op ^ 3});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}
		}
		if(g[x][y] == 'B'){
			a = x + dx[op], b = y + dy[op];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op] > w + 1){
				dis[a][b][op] = w + 1;
				q.push_back({a, b, w + 1, op});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}

			a = x + dx[op ^ 1], b = y + dy[op ^ 1];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 1] > w){
				dis[a][b][op ^ 1] = w;
				q.push_front({a, b, w, op ^ 1});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w);
			}

			a = x + dx[op ^ 3], b = y + dy[op ^ 3];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 3] > w + 1){
				dis[a][b][op ^ 3] = w + 1;
				q.push_back({a, b, w + 1, op ^ 3});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}
		}
		if(g[x][y] == 'C'){
			a = x + dx[op], b = y + dy[op];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op] > w + 1){
				dis[a][b][op] = w + 1;
				q.push_back({a, b, w + 1, op});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}

			a = x + dx[op ^ 1], b = y + dy[op ^ 1];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 1] > w + 1){
				dis[a][b][op ^ 1] = w + 1;
				q.push_back({a, b, w + 1, op ^ 1});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w + 1);
			}

			a = x + dx[op ^ 3], b = y + dy[op ^ 3];
			if(a >= 0 && a < n && b >= 0 && b < m && dis[a][b][op ^ 3] > w){
				dis[a][b][op ^ 3] = w;
				q.push_front({a, b, w, op ^ 3});
			}
			if(a == n - 1 && b == m){
				ans = min(ans, w);
			}
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