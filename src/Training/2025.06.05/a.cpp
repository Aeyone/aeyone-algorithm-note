#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int s = 1e9, t = 1e9;//默认s大于t
	int ans = 0;
	for(auto e : a){
		if(e > t && e <= s)
			s = e;
		else{
			t = e;
			if(e > s)
				ans ++;
		}
		if(s < t)
			swap(s, t);
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