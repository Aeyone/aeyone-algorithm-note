#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	string s;
	
	if(n2 == 0 && n3 == 0)
		s += "0";

	if(n2 % 2 == 0 && n2 != 0)
		s += "0", n2 --;

	if(n3 || n2)
		s += "1";
	while(n3 --)
		s += "1";

	while(n2 --){
		if(n2 % 2 == 0)
			s += "0";
		else
			s += "1";
	}
	if(n2 == 0 && n3 == 0)
		s += "0";

	while(n1 --)
		s += "0";

	cout << s << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}