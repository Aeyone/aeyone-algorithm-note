#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vector<int>> pos(n, vector<int>(k, n));
	for(int i = n - 1; i > 0; i --){
		pos[i - 1] = pos[i];
		pos[i - 1][s[i] - 'a'] = i;
	}
	
	vector<int> d(n + 1, n), st;
	st = pos[0], st[s[0] - 'a'] = 0;
	d[n] = 0;
	for(int i = n - 1; i >= 0; i --)
		for(int j = 0; j < k; j ++)
			d[i] = min(d[i], d[pos[i][j]] + 1);
		
	int q;
	cin >> q;
	while(q --){
		string t;
		cin >> t;
		int idx = -1;
		for(auto e : t){
			idx = (idx == -1 ? st[e - 'a'] : pos[idx][e - 'a']);
			if(idx == n)
				break;
		}
		cout << d[idx] << '\n';
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