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
	vector<string> g(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> g[i];
		g[i] = " " + g[i];
	}
	int pos[2] {};
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(g[i][j] == 'T'){
				pos[0] = i, pos[1] = j;
			}
			cnt += (g[i][j] == '#');
		}
	}
	if(cnt == 0){
		cout << 0 << '\n';
		return;
	}
	int f[n + 1][n + 1][m + 1][m + 1][2 * n + 1][2 * m + 1] {};
	memset(f, 0x3f, sizeof f);

	f[1][n][1][m][n][m] = 0;
	queue<array<int, 6>> q;

	q.push({1, n, 1, m, n, m});
	int ans = INF;
	while(q.size()){
		auto [lx, rx, ly, ry, x, y] = q.front();//x的意义为，T在x方向上的位移，y同理
		q.pop();
		for(int i = 0; i < 4; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a > 2 * n || b < 0 || b > 2 * m){
				continue;
			}
			int xx = (pos[0] + a - n), yy = (pos[1] + b - m);
			if(xx >= lx && xx <= rx && yy >= ly && yy <= ry && g[xx][yy] == '#'){//在范围内且是垃圾，不能移动
				continue;
			}
			int lxx = max(lx, 1 + a - n);//1 + (x - n) 为实际的lx
			int rxx = min(rx, a);//n + (x - n) 为实际的rx

			int lyy = max(ly, 1 + b - m);
			int ryy = min(ry, b);
			if(lxx > rxx || lyy > ryy){
				cout << f[lx][rx][ly][ry][x][y] + 1 << '\n';
				return;
			}
			if(f[lxx][rxx][lyy][ryy][a][b] == 0x3f3f3f3f){
				f[lxx][rxx][lyy][ryy][a][b] = f[lx][rx][ly][ry][x][y] + 1;
				int cnt = 0;
				for(int i = lxx; i <= rxx; i ++){
					for(int j = lyy; j <= ryy; j ++){
						cnt += (g[i][j] == '#');
					}
				}	
				// cerr << "delta = " << dx[i] << ' ' << dy[i] << '\n';
				// cerr << "ans = " << f[lxx][rxx][lyy][ryy][a][b] << ' ';
				// cerr << "cnt = " << cnt << '\n';
				// cerr << "x = " << x - n << " y = " << y - m << '\n';
				// cerr << "xx = " << xx  << " yy = " << yy << '\n';
				// cerr << "lastRangeX = " << lx << " ~ " << rx << ' ';
				// cerr << "lastRangeY = " << ly << " ~ " << ry << '\n';
				// cerr << "curRangeX = " << lxx << " ~ " << rxx << ' ';
				// cerr << "curRangeY = " << lyy << " ~ " << ryy << '\n';
				// cerr << "-------------------------------" << '\n';
				if(!cnt){
					cout << f[lxx][rxx][lyy][ryy][a][b] << '\n';
					return;
				}
				q.push({lxx, rxx, lyy, ryy, a, b});
			}
		}
	}
	cout << -1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}