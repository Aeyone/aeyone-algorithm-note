#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	multiset<int> st;
	for(int i = 0; i < m; i ++){
		cin >> a[i];
		st.insert(a[i]);
	}
	vector<array<int, 2>> res(n);
	for(int i = 0; i < n; i ++){
		auto mx = st.begin();
		auto mn = (--st.end());
		if(i % 2 == 0)
			res[i] = {*mn, *mx};
		else{
			res[i] = {*mx, *mn};
			st.erase(mx), st.erase(mn);
		}
	}
	for(auto [x, y] : res){
		for(int i = 0; i < 3; i ++)
			cout << x << " " << y << " ";
		cout << '\n';
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