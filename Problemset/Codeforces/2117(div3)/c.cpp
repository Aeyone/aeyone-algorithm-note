#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<bool> vis(n + 10, false);
	set<int> st;
	int bef = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		st.insert(a[i]);
		if(vis[a[i]])
			bef --;

		if(bef == 0){
			for(auto e : st)
				vis[e] = true;
			ans ++;
			bef = st.size();
			// cout << bef << '\n';
			st.clear();
		}
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