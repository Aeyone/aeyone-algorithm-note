#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<vector<int>>> g(3, vector<vector<int>> (3));// ab 0 1, ac 0 2, ba 1 0, ca 2 0, cb 2 1, bc 1 2
	for(int i = 0; i < q; i ++){
		char x, y;
		cin >> x >> y;
		g[x - 'a'][y - 'a'].push_back(i);
	}
	for(int i = 0; i <= 2; i ++){
		for(int j = 0; j <= 2; j ++){
			if(i == j)
				continue;
			sort(g[i][j].begin(), g[i][j].end(), greater<int>{});
		}
	}

	for(int i = 0; i < n; i ++){
		if(s[i] == 'a')
			continue;
		int e = s[i] - 'a';
		if(g[e][0].size()){
			g[e][0].pop_back();
			s[i] = 'a';
		}else if(g[e][3 - e].size() && g[3 - e][0].size()){
			int tmp = g[e][3 - e].back();
			int l = 0, r = g[3 - e][0].size() - 1, to = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(g[3 - e][0][mid] > tmp)
					to = mid, l = mid + 1;
				else
					r = mid - 1;
			}
			if(to != -1){
			// cout << "to = " << g[3 - e][0][to] << '\n';
				g[3 - e][0][to] = -1;
				g[e][3 - e].pop_back();
				s[i] = 'a';
			}else if(e == 2 && g[e][3 - e].size()){
				g[e][3 - e].pop_back();
				s[i] = 'b';
			}
		}else if(e == 2 && g[e][3 - e].size()){
			g[e][3 - e].pop_back();
			s[i] = 'b';
		}
		while(g[e][0].size() && g[e][0].back() == -1)
			g[e][0].pop_back();

		while(g[3 - e][0].size() && g[3 - e][0].back() == -1)
			g[3 - e][0].pop_back();
	}
	cout << s << '\n';
}


signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}