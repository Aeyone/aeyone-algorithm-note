#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		g[b[i]].push_back(i);
	}
	bool ok = true;
	for(int i = 1; i <= n; i ++){
		ok &= (g[i].size() % i == 0);
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	vector<int> res(n);
	int idx = 1;
	map<int, int> cnt;
	for(int i = 1; i <= n; i ++){
		for(auto j : g[i]){
			res[j] = idx;
			cnt[idx] ++;
			if(cnt[idx] == i)
				idx ++;
		}
	}
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}