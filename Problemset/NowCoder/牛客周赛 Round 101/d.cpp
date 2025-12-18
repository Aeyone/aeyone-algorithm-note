#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	bool ok = (m & 1);
	vector<int> v;
	for(int i = 0; (m >> i) > 0; i ++){
		if((m >> i) & 1){
			ok &= ((1 << i) <= n);
			v.push_back((1 << i));
		}
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}
	vector<int> vis(n + 1);
	int len = v.size();
	while(v.back() != 1){
		cout << v.back() << ' ';
		vis[v.back()] = true;
		v.pop_back();
	}
	for(int i = 1; i <= n; i ++){
		if(!vis[i])
			cout << i << ' ';
	}
	cout << '\n';
	cout << len << '\n';
	int idx = 1;
	while(idx < len)
		cout << idx << ' ' << idx << '\n', idx ++;
	cout << idx << ' ' << n << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}