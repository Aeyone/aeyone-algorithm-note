#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int st = 0;
	if(n & 1){
		cout << s.substr(0, 3);
		st = 3;
		if(n != 3)
			cout << "-";
	}
	for(int i = st; i < n; i += 2){
		cout << s[i] << s[i + 1];
		if(i + 2 < n)
			cout << "-";
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}