#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
char c[3] = {'r', 'e', 'd'};

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "&" + s + "&";
	string backup = s;
	for(int i = 2; i <= n; i ++){
		if(s[i] != s[i - 1])
			continue;
		for(int j = 0; j < 3; j ++)
			if(c[j] != s[i - 1] && c[j] != s[i + 1])
				s[i] = c[j];
	}
	for(int i = 1; i <= n; i ++)
		cout << s[i];
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