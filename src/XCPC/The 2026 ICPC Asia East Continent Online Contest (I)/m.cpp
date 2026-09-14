#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve () {
	int n, m;
	cin >> n >> m;
	map<string, int> mp;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		mp[s] = -1;
	}
	for (int i = 0; i < m; i ++) {
		string s;
		cin >> s;
		if (mp.find(s) != mp.end()) {
			if (mp[s] == -1) {
				mp[s] = 1;
				cout << "OK" << '\n';
			} else {
				cout << "REPEAT" << '\n';
			}
		} else {
			cout << "WRONG" << '\n';
		}
	}
}

signed main () {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}