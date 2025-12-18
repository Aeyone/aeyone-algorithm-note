#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k;
	cin >> k;
	vector<pair<int, int>> res;
	int siz = 0;
	while(k - siz >= 0){
		res.push_back({siz, 0}), k -= siz, siz ++;
		// cout << "k = " << k << '\n';
	}

	// cout << "k = " << k << '\n';
	siz = 1;
	for(int i = 0; k > 0; i ++){
		int cnt = 1;
		while(k - cnt >= 0){
			res.push_back({i, siz}), siz ++, k -= cnt ++;
			// cout << "k = " << k << '\n';
		}
	}

	cout << res.size() << '\n';
	for(auto [x, y] : res)
		cout << x << ' ' << y << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}