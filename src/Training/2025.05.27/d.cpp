#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	bool ok = true;
	set<char> cnt;
	for(string e : s)
		ok &= (count(e.begin(), e.end(), e.front()) == m), cnt.insert(e.front());

	for(int i = 1; i < n; i ++)
		ok &= (s[i][0] != s[i - 1][0]);
	
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}