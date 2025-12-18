#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x7f7f7f7f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	sort(a.begin(), a.end());
	int ans = -inf;
	for(int i = 0; i < n; i += 2){
		ans = max(ans, abs(a[i] - a[i + 1]));
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