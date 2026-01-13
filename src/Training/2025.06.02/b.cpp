#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int dfs(string s, int u){
	if(s.size() == 1)
		return (s[0] - 'a' != u);

	int res = 0;
	int c1 = 0, c2 = 0;
	for(int i = 0; i < s.size() / 2; i ++)
		c1 += (s[i] - 'a' != u);
	for(int i = s.size() / 2; i < s.size(); i ++)
		c2 += (s[i] - 'a' != u);

	int a = dfs(s.substr(s.size() / 2, s.size() / 2), u + 1);
	int b = dfs(s.substr(0, s.size() / 2), u + 1);
	res = min(c1 + a, c2 + b);
	return res;
}

void solve() {
	int n;
	cin >> n;
	int cnt = 1;
	while(n)
		cnt <<= 1, n >>= 1;
	string s;
	cin >> s;
	cout << dfs(s, 0) << '\n';
	// cout << s.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}