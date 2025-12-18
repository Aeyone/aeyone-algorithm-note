#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	if(s == "red")
		cout << "SSS" << '\n';
	else if(s == "blue")
		cout << "FFF" << '\n';
	else if(s == "green")
		cout << "MMM" << '\n';
	else
		cout << "Unknown" << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}