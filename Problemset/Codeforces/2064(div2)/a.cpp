#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s, res;
	cin >> s;
	res += s[0];
	for(int i = 1; i < n; i ++){
		if(s[i] != s[i - 1])
			res += s[i];
	}
	s = res;
	cout << count(s.begin(), s.end(), '1') * 2 - (s.back() == '1') << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}