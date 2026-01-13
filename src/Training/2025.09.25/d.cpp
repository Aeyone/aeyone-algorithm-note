#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int x = 0;
	for(int i = 0; i < n; i ++){
		x += (a[i] != b[i]);
	}
	int cb1 = count(b.begin(), b.end(), '1');
	int ca1 = count(a.begin(), a.end(), '1');
	int ans = 1e9;
	if(ca1 == cb1){
		ans = x;
	}
	if(n - ca1 + 1 == cb1){
		ans = min(ans, n - x);
	}
	if(ans == 1e9){
		ans = -1;
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