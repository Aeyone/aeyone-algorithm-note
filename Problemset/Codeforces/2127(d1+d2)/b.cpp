#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;

	if(count(s.begin(), s.end(), '#') == 0 || x == 1 || x == n){
		cout << 1 << '\n';
		return;
	}
	int p1 = x - 1, p2 = x - 1;
	while(p1 >= 0){
		if(s[p1] == '#')
			break;
		p1 --;
	}
	while(p2 < n){
		if(s[p2] == '#')
			break;
		p2 ++;
	}
	if(s[x - 2] == '#' || s[x] == '#')
		cout << min(x, n - x + 1) << '\n';
	else
		cout << max(min(p1 + 2, n - x + 1), min(n - p2 + 1, x)) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}