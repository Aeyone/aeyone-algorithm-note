#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k;
	cin >> k;
	string res;
	if(k & 1)
		res += '4';
	k >>= 1;
	for(int i = 0; i < k; i ++)
		res += '8';
	if(res.size() == 0)
		res = "1";
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}