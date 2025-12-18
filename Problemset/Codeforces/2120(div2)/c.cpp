#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, m;
	cin >> n >> m;
	if(n * (n + 1) / 2 < m || n > m){
		cout << -1 << '\n';
		return;
	}
	vector<bool> vis(n + 1);
	vector<int> res;
	int t = n;
	i64 sum = 0;
	while(sum + n - res.size() < m){
		while(sum + t + n - res.size() - 1 > m)
			t --;
		res.push_back(t);
		vis[t] = true;
		sum += t;
		t --;
	}
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
			res.push_back(i);
	
	cout << res.front() << '\n';
	for(int i = 0; i < res.size() - 1; i ++){
		cout << res[i] << ' ' << res[i + 1] << '\n';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}