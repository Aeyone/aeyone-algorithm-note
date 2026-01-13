#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	getline(cin, s);

	while(s.back() == ' ' || s.back() == '?')
		s.pop_back();
	
	char la[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
	bool ok = false;
	for(int i = 0; i < 12; i ++)
		ok |= (s.back() == la[i]);

	if(ok)
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