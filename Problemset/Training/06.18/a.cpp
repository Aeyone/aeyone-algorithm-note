#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 k, cnt = 1;
	cin >> k;
	vector<int> a(10, 1);
	int u = 0;
	while(cnt < k)
		cnt = (cnt / a[u] * (++ a[u])), u = (u + 1) % 10;

	string t = "codeforces";
	string res;
	for(int i = 0; i < 10; i ++)
		while(a[i])
			res += t[i], a[i] --;
		
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}