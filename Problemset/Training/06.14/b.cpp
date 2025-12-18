#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool ok = true;
	int c1 = 0, c0 = 0;
	for(int i = 0; i < k; i ++){
		if(s[i] == '1')
			c1 ++;
		if(s[i] == '0')
			c0 ++;
		
		if(s[i] == '?' && i + k < n)
			s[i] = s[i + k];
	}
	for(int i = 0; i < n - k; i ++){
		if(s[i + k] == '?')
			s[i + k] = s[i];
		ok &= (s[i] )
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}