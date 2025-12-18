#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	string s1 = to_string(a);
	string s2 = to_string(b);
	int mx = 0;
	for(auto e : s1)
		mx = max(mx, e - '0');
	for(auto e : s2)
		mx = max(mx, e - '0');
	mx ++;
	int ans = 0;
	int sum = stoi(s1, nullptr, mx) + stoi(s2, nullptr, mx);
	while(sum){
		sum /= mx;
		ans ++;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}