#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = count(s.begin(), s.end(), '1') * 11;
	int l = 0, r = n - 1;
	while(l < n && s[l] == '0')
		l ++;
	while(r >= 0 && s[r] == '0')
		r --;
	if(ans == 0)
		k = 0;
	if(n - r - 1 <= k)
		k -= (n - r - 1), ans -= 10;
	if(l <= k && ans > 1)
		ans --;
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