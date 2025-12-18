#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> vis(n, false);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	int ans = 0;
	for(int i = 0; i < n; i ++){
		if(vis[i])
			continue;
		for(int j = i + 1; j < n; j ++){
			if(vis[j])
				continue;
			if((a[i] + a[j]) % 3 == 0){
				vis[i] = vis[j] = true;
				ans ++;
				break;
			}
		}
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