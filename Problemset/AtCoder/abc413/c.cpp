#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int q;
	cin >> q;
	vector<pair<int, int>> v;
	int h = 0;
	while(q --){
		int x;
		cin >> x;
		if(x == 1){
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}
		if(x == 2){
			int k;
			cin >> k;
			i64 sum = 0;
			while(k && h < v.size()){
				int cnt = v[h].first;
				v[h].first -= k;
				sum += (i64)v[h].second * min(k, cnt);
				if(v[h].first <= 0)
					h ++;
				k = max(0, k - cnt);
			}
			cout << sum << '\n';
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}