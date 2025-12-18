#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++)
			cin >> g[i][j];
	}
	vector<int> p(n + m);
	i64 sum = 0;
	for(int i = 1; i < n + m; i ++)
		cin >> p[i], sum += p[i];

	auto check = [&](i64 x)->bool{
		queue<pair<int, int>> q;
		vector<vector<i64>> dist(n + 1, vector<i64>(m + 1));
		vector<vector<int>> vis(n + 1, vector<int>(m + 1));

		q.push({1, 1});
		dist[1][1] = x;
		vis[1][1] = true;
		int day = 1;
		bool ok = false;
		while(q.size()){
			int siz = q.size();
			while(siz --){
				auto now = q.front();
				q.pop();

				int a = now.first, b = now.second;
				i64 coin = dist[a][b] + g[a][b] - p[day];

				if(a == n && b == m)
					ok |= (coin >= 0);
				
				if(coin >= 0){
					if(a + 1 <= n){
						if(!vis[a + 1][b])
							q.push({a + 1, b}), vis[a + 1][b] = true;
						
						dist[a + 1][b] = max(dist[a + 1][b], coin);
					}
					if(b + 1 <= m){
						if(!vis[a][b + 1])
							q.push({a, b + 1}), vis[a][b + 1] = true;

						dist[a][b + 1] = max(dist[a][b + 1], coin);
					}
				}
			}
			day ++;
		}
		return ok;
	};
	i64 l = 0, r = sum, ans = 0;
	while(l <= r){
		i64 mid = (l + r) >> 1;
		if(check(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}