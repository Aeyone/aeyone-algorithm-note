#include <bits/stdc++.h>
using namespace std;

#define int long long

int c[20], k[200], a[200][20], path[20];
int ans = 1e18;
int n, m;

void dfs(int u, int cnt){
	if(u == n){
		bool ok = true;
		for(int i = 1; i <= m; i ++){
			int cnt = 0;
			for(int j = 1; j <= k[i]; j ++)
				cnt += path[a[i][j]];
			ok &= (cnt >= 2);
		}
		int sum = 0;
		for(int i = 1; i <= n; i ++)
			sum += path[i] * c[i];

		if(ok)
			ans = min(ans, sum);
		return;
	}

	for(int i = 0; i < 3; i ++){
		path[u + 1] = i;
		dfs(u + 1, i);
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];

	for(int i = 1; i <= m; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++)
			cin >> a[i][j];
	}

	dfs(0, 0);
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