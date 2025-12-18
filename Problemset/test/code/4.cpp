#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

void solve() {
	int n, m;
	cin >> n >> m;
	int l, r;
	cin >> l >> r;
	vector<string> g(n);
	vector<vector<i64>> odd(n, vector<i64>(m, inf)), even(n, vector<i64>(m, inf));
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	vector<vector<bool>> v1(n, vector<bool>(m)), v2(n, vector<bool>(m));
	queue<pair<int, int>> q;
	q.push({0, 0});
	even[0][0] = 0;
	v2[0][0] = true;
	while(q.size()){
		auto now = q.front();
		q.pop();
		int x = now.first, y = now.second;
		for(int i = 0; i < 8; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '0')
				continue;
			if(odd[a][b] > even[x][y] + 1 && !v1[a][b]){
				odd[a][b] = even[x][y] + 1;
				v1[a][b] = true;
				q.push({a, b});
			}
			if(even[a][b] > odd[x][y] + 1 && !v2[a][b]){
				even[a][b] = odd[x][y] + 1;
				v2[a][b] = true;
				q.push({a, b});
			}
		}
	}
	i64 d = inf;
	if(l == r && !(l & 1))
		d = even[n - 1][m - 1];
	else
		d = min(even[n - 1][m - 1], odd[n - 1][m - 1]);

	if(d >= inf){
		cout << -1 << '\n';
		return;
	}
	int x = (d + r - 1) / r;
	cout << x << '\n';
	if(l != r){
		cout << x << '\n';
	}else{
		if(l % 2 == 0)
			cout << x << '\n';
		else{
			if((d ^ x) & 1)
				cout << x + 1 << '\n';
			else
				cout << x << '\n';
		}
	}
	

	// for(int i = 0; i < n; i ++){
	// 	for(int j = 0; j < m; j ++){
	// 		if(odd[i][j] == inf)
	// 			cout << -1 << ' ';
	// 		else
	// 			cout << odd[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << '\n';
	// for(int i = 0; i < n; i ++){
	// 	for(int j = 0; j < m; j ++){
	// 		if(even[i][j] == inf)
	// 			cout << -1 << ' ';
	// 		else
	// 			cout << even[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}