#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> a;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		a.insert(x);
	}
	if(k == 1 && a.size() > 1){
		cout << -1 << '\n';
		return;
	}
	int x = a.size() - k;
	int ans = 1;
	while(x > 0){
		x -= (k - 1);
		ans ++;
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