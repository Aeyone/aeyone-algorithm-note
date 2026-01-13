#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	bool vis[3010] = {};
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i], vis[a[i]] = true;

	for(int i = 1; i <= 3001; i ++){
		if(!vis[i]){
			cout << i << '\n';
			break;
		}
	}

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}