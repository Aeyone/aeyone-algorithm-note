#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> c(n), d(m);
	for(auto &e : c){
		cin >> e;
	}
	for(auto &e : d){
		cin >> e;
	}
	int x;
	cin >> x;
	map<string, int> mp;
	for(int i = 0; i < m; i ++){
		int x;
		cin >> x;
		mp[d[i]] = x;
	}
	i64 sum = 0;
	for(auto e : c){
		if(mp.find(e) != mp.end()){
			sum += mp[e];
		}else{
			sum += x;
		}
	}
	cout << sum << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}