#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string n;
	getline(cin, n);
	int x = stoi(n);
	cout << n << " nya\n";
	for(int i = 0; i < x; i ++){
		string s;
		getline(cin, s);
		cout << s << " nya\n";
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}