#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> p;
	for(int i = 0; i < n; i ++)
		if(s[i] == '*')
			p.push_back(i);
	int mid = p.size() / 2;
	i64 ans = 0;
	for(int i = 0; i < p.size(); i ++){
		int d = abs(mid - i);
		ans += abs(p[mid] - p[i]) - d;
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