#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	map<char, int> mp;
	for(int i = 0; i < s1.size(); i ++)
		mp[s1[i]] ++;
	for(int i = 0; i < s2.size(); i ++){
		if(s2[i] == ' ')
			continue;
		mp[s2[i]] --;
		if(mp[s2[i]] < 0){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}