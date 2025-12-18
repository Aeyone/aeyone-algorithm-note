#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	i64 a = count(s.begin(), s.end(), '-'), b = count(s.begin(), s.end(), '_');
	int cnt = 1;
	a --;
	i64 ans = max(0ll, a * b);
	while(a > 0){
		ans = max(ans, (-- a) * b * (++ cnt));
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