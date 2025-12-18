#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s2.begin(), s2.end());
	if(s1 == s2)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}