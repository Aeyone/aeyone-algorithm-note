#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<i64>> g(n, vector<i64>(m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> g[i][j];

	auto run =[&](int tmp)->void{
		int x = n - 1, y = m - 1;
		for(int i = s.size() - 1; i >= 0; i --){
			i64 sum = 0;
			if(s[i] == 'D'){
				for(int j = 0; j < m; j ++) if(j != y){
					sum += g[x][j];
				}
				g[x][y] = tmp - sum;
				x --;
			}else if(s[i] == 'R'){
				for(int j = 0; j < n; j ++) if(j != x){
					sum += g[j][y];
				}
				g[x][y] = tmp - sum;
				y --;
			}
		}
	};
	run(0);
	for(int i = 1; i < m; i ++)
		g[0][0] -= g[0][i];

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}