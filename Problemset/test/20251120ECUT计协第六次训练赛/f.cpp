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

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	int mn = INF;
	for(int i = 0; i < n; i ++){
		int m;
		cin >> m;
		g[i].resize(m);
		for(int j = 0; j < m; j ++){
			cin >> g[i][j];
			mn = min(mn, g[i][j]);
		}
		sort(g[i].begin(), g[i].end());
	}
	i64 ans = mn;
	int nemn = INF;
	for(int i = 0; i < n; i ++){
		nemn = min(nemn, g[i][1]);
		ans += g[i][1];
	}
	cout << ans - nemn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}