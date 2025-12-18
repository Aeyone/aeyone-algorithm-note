#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> ans;
	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			int x;
			cin >> x;
			a[i][j] = a[j][i] = x;
			if(x == (i ^ j)){
				ans.push_back({i, j});
			}
		}
	}
	for(auto [u, v] : ans){
		bool ok = true;
		for(int i = 1; i <= n; i ++){
			ok &= ((a[u][i] ^ a[i][v]) == v || (a[v][i] ^ u) == a[u][i]);
		}
		if(ok){
			cout << u << ' ' << v << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}