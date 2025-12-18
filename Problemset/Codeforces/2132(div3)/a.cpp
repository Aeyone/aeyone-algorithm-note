#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n1, n2;
	string a, b;
	cin >> n1;
	cin >> a;
	cin >> n2;
	cin >> b;
	string s;
	cin >> s;
	for(int i = 0; i < n2; i ++){
		if(s[i] == 'D')
			a += b[i];
		else
			a = b[i] + a;
	}
	cout << a << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}