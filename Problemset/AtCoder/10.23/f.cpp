#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m, h, k;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	map<array<int, 2>, bool> mp;
	while(m --){
		int x, y;
		cin >> x >> y;
		mp[{x, y}] = true;
	}
	bool ok = true;
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
	vector<int> idx(26, -1);
	idx['R' - 'A'] = 0;
	idx['L' - 'A'] = 1;
	idx['U' - 'A'] = 2;
	idx['D' - 'A'] = 3;
	int x = 0, y = 0;
	for(auto e : s){
		x = x + dx[idx[e - 'A']], y = y + dy[idx[e - 'A']];
		h --;
		ok &= (h >= 0);
		if(mp.find({x, y}) != mp.end()){
			if(h < k){
				h = k;
				mp.erase({x, y});
			}
		}
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
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