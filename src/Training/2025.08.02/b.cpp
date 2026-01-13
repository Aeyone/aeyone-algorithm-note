#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int c[2] = {};
	c[0] = count(s.begin(), s.end(), '0');
	c[1] = count(s.begin(), s.end(), '1');
	vector<int> ans(n - 1);
	for(int i = 0; i < n - 1; i ++){
		c[s[i] - '0'] --;
		ans[i] = c[1] - c[0];
	}
	sort(ans.begin(), ans.end(), greater<int>{});
	i64 sum = 0, cnt = 1;
	for(auto e : ans){
		if(e < 0 || sum >= k)
			break;
		sum += e, cnt ++;
	}
	if(sum >= k)
		cout << cnt << '\n';
	else
		cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}