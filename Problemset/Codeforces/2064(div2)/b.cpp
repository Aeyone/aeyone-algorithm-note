#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), cnt(n + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	for(int i = 0; i < n; i ++)
		b[i] = (cnt[a[i]] > 1);
	
	int l = 0, r = -1;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i ++){
		// cout << b[i] << ' ';
		if(b[i] == 1){
			if(r - l != -1)
				v.push_back({l, r});
			l = i + 1;
			r = i;
		}else
			r ++;
	}
	if(r - l != -1)
		v.push_back({l, r});
	// cout << '\n';
	pair<int, int> p = {0, -10000};
	for(auto [x, y] : v){
		// cout << x << ' ' << y << '\n';
		if(y - x > p.second - p.first)
			p = {x, y};
	}

	if(p.second >= 0)
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	else
		cout << 0 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}