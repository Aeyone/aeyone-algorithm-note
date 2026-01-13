#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<i64> s(n);
	s[0] = a[0];
	for(int i = 1; i < n; i ++)
		s[i] = s[i - 1] + a[i];

	map<i64, int> l;
	l[0] = 0;
	vector<pii> v;
	for(int i = 0; i < n; i ++){
		if(l.find(s[i]) == l.end())
			l[s[i]] = i + 1;
		else
			v.push_back({l[s[i]], i}), l[s[i]] = i + 1;
	}
	
	sort(v.begin(), v.end());
	int ed = 1e9, ans = (v.size() > 0);
	for(auto [x, y] : v){
		if(x >= ed)
			ans ++, ed = y;
		else if(y < ed)
			ed = y;
		// cout << "ed:" << ed << "| " << x << ' ' << y << '\n';
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