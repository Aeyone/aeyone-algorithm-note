#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	i64 x = 0, ans = n;
	multiset<i64> st;
	for(int i = 1; i <= n; i ++){
		x += a[i];
		st.insert(a[i]);
		if(x < 0){
			x -= *st.begin();
			st.erase(st.begin());
			ans --;
		}
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