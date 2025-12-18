/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//树形dp
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i][0] >> a[i][1];
	}
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<array<i64, 2>> dp(n);
	auto dfs = [&](auto &&self, int u, int fa)->void{
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			dp[u][0] += max(dp[v][0] + abs(a[u][0] - a[v][0]), dp[v][1] + abs(a[u][0] - a[v][1]));
			dp[u][1] += max(dp[v][0] + abs(a[u][1] - a[v][0]), dp[v][1] + abs(a[u][1] - a[v][1]));
		}
	};
	dfs(dfs, 0, -1);
	cout << max(dp[0][0], dp[0][1]) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}