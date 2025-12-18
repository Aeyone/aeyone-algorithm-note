#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s = to_string(n);

	int cnt = n % 10;
	s.pop_back();

	int ans = min(7, cnt + 3);//处理末尾
	if(cnt >= 7)
		ans = min(ans, cnt - 7);//处理末尾

	while(s.back() == '0')
		s.pop_back();

	int x = s.back() - '0';//
	if(x <= 7)
		ans = min(ans, 7 - x + (7 - x > cnt ? 1 : 0));
	if(x == 8)
		ans = min(ans, cnt + 1);

	s.pop_back();
	for(auto e : s){
		int x = e - '0';
		if(x <= 7)
			ans = min(ans, 7 - x);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}