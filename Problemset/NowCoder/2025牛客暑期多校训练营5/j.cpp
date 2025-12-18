#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<pair<int, int>> pos;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> g[i][j];
			if(g[i][j] == 1)
				pos.push_back({i, j});
		}
	}
	if(!pos.size()){
        cout << (n / 2 + m / 2) << "\n";
        return;
    }
	vector<int> dx = {0, -1, 1, 0}, dy = {-1, 0, 0, 1};
	auto check = [&](int sec)->bool{
		vector<vector<int>> mp = g;
		queue<pair<int, int>> q;
		for(auto [x, y] : pos)
			q.push({x, y});
		
		int T = 0;
		while(q.size() && T < sec){
			int siz = q.size();
			while(siz --){
				auto now = q.front();
				q.pop();
				for(int i = 0; i < 4; i ++){
					int a = now.first + dx[i], b = now.second + dy[i];
					if(a < 0 || b < 0 || n <= a || m <= b || mp[a][b])
						continue;
					mp[a][b] = 1;
					q.push({a, b});
				}
			}
			T ++;
		}
		vector<pair<int, int>> v;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(mp[i][j] == 0)
					v.push_back({i, j});

		int ll = inf, rr = -inf, u = inf, d = -inf;
		for(auto [x, y] : v){
			// cout << x << ' ' << y << '\n';
			ll = min(ll, x + y);
			rr = max(rr, x + y);
			u = min(u, x - y);
			d = max(d, x - y);
		}
		// cout << ll << ' ' << rr << ' ' << u << ' ' << d << '\n';
		// for(int i = 0; i < n; i ++){
		// 	for(int j = 0; j < m; j ++)
		// 		cout << mp[i][j] << ' ';
		// 	cout << '\n';
		// }
		// cout << "! " << sec << '\n';
		return (!v.size() || (rr - ll <= 2 * sec && d - u <= 2 * sec));
	};
	// cout << check(g, 2) << '\n';
	int l = 0, r = m * n, ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
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