#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	vector<int> pre(n + 2), suf(n + 1);
	suf[0] = 0, pre[n + 1] = n + 1;
	for(int i = 1; i <= n; i ++)
		suf[i] = (s[i] == '#' ? i : suf[i - 1]);
	for(int i = n; i >= 1; i --)
		pre[i] = (s[i] == '#' ? i : pre[i + 1]);

	while(q --){
		int x, y;
		cin >> x >> y;
		if(x > y)
			swap(x, y);
		cout << max(0, suf[y] - pre[x] + 1) << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}