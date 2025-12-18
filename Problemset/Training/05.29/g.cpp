#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
bool vis[2010][2010];

void solve() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    queue<array<int, 2>> q;

	array<int, 2> ans = {-1, -1};
    for(int i = 0; i < k; i ++){
    	int a, b;
    	cin >> a >> b;
    	vis[a][b] = true;
    	q.push({a, b});
    	ans = {a, b};
    }

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    while(q.size()){
    	auto now = q.front();
    	q.pop();
    	for(int i = 0; i < 4; i ++){
    		int a = now[0] + dx[i], b = now[1] + dy[i];
    		if(a <= 0 || b <= 0 || a > n || b > m || vis[a][b])
    			continue;
    		vis[a][b] = true;
    		ans = {a, b};
    		q.push(ans);
    	}
    }
    cout << ans[0] << " " << ans[1] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}