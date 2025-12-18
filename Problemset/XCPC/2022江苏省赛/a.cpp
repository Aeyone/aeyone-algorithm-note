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
	vector<pair<string, string>> v(n);
	map<string, int> mp;

	for(int i = 0; i < n; i ++){
		cin >> v[i].first >> v[i].second;
		mp[v[i].first] = 1;
		mp[v[i].second] = 1;
	}

	int idx = 0;
	for(auto &[_, e] : mp){
		e = idx ++;
	}
	vector<string> tos(idx);
	for(auto &[e, i] : mp){
		tos[i] = e;
	}
	vector<vector<int>> g(idx);
	for(auto [k, d] : v){
		g[mp[k]].push_back(mp[d]);
	}
	bool ok = false;
	for(int i = 0; i < idx; i ++){
		int N = g[i].size();
		for(int l = 0; l < N; l ++){
			vector<int> vis(idx);
			int cnt = 0;
			int r = l;
			while(r < N && !vis[g[i][r]]){
				vis[g[i][r]] = true;
				r ++;
				cnt ++;
			}
			ok |= (cnt == 5);
		}
	}
	if(ok){
		cout << "PENTA KILL!" << '\n';
	}else{
		cout << "SAD:(" << '\n';
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