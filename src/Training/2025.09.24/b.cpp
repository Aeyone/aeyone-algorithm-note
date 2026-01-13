#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;
vector<int> p;

void build(int MAX){
	vector<bool> vis(MAX + 1);
	for(int i = 2; i <= MAX; i ++){
		if(!vis[i])
			p.push_back(i);
		for(int j = 0; j < p.size() && p[j] <= MAX / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

void solve() {
	int x, y;
	cin >> x >> y;
	int d = y - x;
	if(d == 1){
		cout << -1 << '\n';
		return;
	}
	vector<int> v;
	for(int i = 0; i < p.size(); i ++){
		if(d % p[i] == 0){
			while(d % p[i] == 0){
				d /= p[i];
			}
			v.push_back(p[i]);
		}
	}
	if(d > 1){
		v.push_back(d);
	}
	int mn = inf;
	for(auto e : v){
		mn = min(mn, (e - (x % e)) % e);
	}
	cout << mn << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	build(1e4);
	cin >> _;
	while (_ --)
		solve();
}