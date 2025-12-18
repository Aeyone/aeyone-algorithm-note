#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	i64 sum = 0, ans = 0;
	for(auto &e : a){
		cin >> e, sum += e;
		if((int)sqrt(sum) == (double)sqrt(sum) && ((int)sqrt(sum) & 1)){
			ans ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}