#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i = 0; i < n; i ++)
		cin >> t[i];
	int l = -1, r = n, s1 = 0, s2 = 0;
	while(r - l > 1){
		if(s1 == s2)
			l ++, r --, s1 += t[l], s2 += t[r];
		else if(s1 < s2)
			l ++, s1 += t[l];
		else if(s1 > s2)
			r --, s2 += t[r];
		// cout << s1 << " " << s2 << '\n';
	}
	if(l == r)
		r ++;
	cout << l + 1 << " " << n - r << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}