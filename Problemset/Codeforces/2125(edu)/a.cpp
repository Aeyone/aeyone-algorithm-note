#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	string res;
	int t = count(s.begin(), s.end(), 'T');
	int f = count(s.begin(), s.end(), 'F');
	while(t --)
		res += 'T';
	
	for(auto e : s)
		if(e != 'T' && e != 'F')
			res += e;
	
	while(f --)
		res += 'F';

	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}