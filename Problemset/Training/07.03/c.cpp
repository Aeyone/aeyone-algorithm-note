#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k, x, a;
	cin >> k >> x >> a;
	i64 sum = 0;
	for(int i = 0; i <= x; i ++){
		sum += sum / (k - 1) + 1;
		if(sum > a){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}