#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int l, r;
	cin >> l >> r;

	i64 ans = r - l , tmp = r - l;
	for(int i = 1; r / (i64)pow(10, i) > 0; i ++){
		tmp = (tmp + l % 10) / 10;
		l /= 10;
		// cout << ans << "+" << tmp << '\n';
		ans += tmp;
	}
	cout << ans << '\n';
	// int cnt = 0;
	// while(l < r){
	// 	string s0 = to_string(l);
	// 	l ++;
	// 	string s1 = to_string(l);
	// 	if(s0.size() < s1.size())
	// 		s0 = "0" + s0;
	// 	for(int i = 0; i < s1.size(); i ++)
	// 		if(s0[i] != s1[i])
	// 			cnt ++;
	// 	// cout << s0 << " ||| " << s1 << '\n';
	// }
	// cout << cnt << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}