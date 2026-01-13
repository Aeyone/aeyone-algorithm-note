#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	map<string, int> mp;
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		mp[s] ++;
	}
	int mx = 0;
	string ans;
	for(auto [e, x] : mp){
		if(x > mx){
			mx = x;
			ans = e;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}