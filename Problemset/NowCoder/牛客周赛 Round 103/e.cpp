#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	unordered_map<int, bool> mp;
	auto f = [&](auto &&self, string str, int c)->void{
		for(int i = 0; i < str.size(); i ++){
			int x = 0;
			for(int j = i; j < str.size(); j ++){
				if(str[j] == '1')
					x += (1 << (j - i));
				mp[x] = true;
			}
		}
		if(c == 0){
			reverse(str.begin(), str.end());
			self(self, str, 1);
		}
	};

	string path;
	auto dfs = [&](auto &&self, int u, int fa, int cnt)->void{
		string tmp;
		for(int i = max(0, cnt - 20); i <= cnt; i ++)
			tmp += path[i];

		for(auto v : g[u]) if(v != fa){
			path += s[v];
			tmp += s[v];
			f(f, tmp, 0);
			self(self, v, u, cnt + 1);
			path.pop_back();
			tmp.pop_back();
		}
	};
	path += s[0];
	dfs(dfs, 0, -1, 0);
	while(q --){
		int x;
		cin >> x;
		if(mp[x])
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}