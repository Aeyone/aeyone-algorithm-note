#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0;
	while(l < n && s[l] == 'z')
		l ++;
	if(l == n){
		cout << s << '\n';
		return;
	}
	int r = l, d = 'z' - s[l];
	while(r < n && s[r] + d <= 'z')
		r ++;
	for(int i = l; i < r; i ++)
		s[i] += d;
	cout << s << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}