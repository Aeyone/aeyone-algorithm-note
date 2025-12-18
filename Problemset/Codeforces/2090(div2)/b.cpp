using namespace std;
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++)
		cin >> g[i];

	vector<vector<int>> vis(n, vector<int>(m, false));
	bool ok = true;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(g[i][j] == '0'|| i - 1 < 0 || j - 1 < 0){
				vis[i][j] = true;
			}else{
				bool flag = true;
				int k = i;
				while(k >= 0)
					flag &= (g[k --][j] == '1');

				if(!flag){
					flag = true;
					k = j;
					while(k >= 0)
						flag &= (g[i][k --] == '1');
				}
				vis[i][j] = flag;
			}
			ok &= vis[i][j];
			// cout << vis[i][j] << ' ';
		}
		// cout << '\n';
	}
	// cout << "!" << '\n';
	
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}