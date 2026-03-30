#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	map<char, int> mp;
	vector<map<char, int>> dep(n + 1); 
	for (int l = 0, r = 0; l < n; l = r) {
		if (s[l] == 'c' || s[l] == 'p') {
			mp[s[l]] ++;
			r ++;
		} else {
			int dis = mp['p'] - mp['c'];
			while (r < n && (s[r] == 'l' || s[r] == 'r')) {
				if (dis >= 0) {
					dep[dis][s[r ++]] = true;
				} else {
					r ++;
				}
			}
		}
	}
	
	bool ok = true;
	ok &= (mp['p'] == mp['c']);
	for (int i = 0; i <= n; i ++) {
		ok &= (dep[i]['l'] == dep[i]['r']);
	}

	if (ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}