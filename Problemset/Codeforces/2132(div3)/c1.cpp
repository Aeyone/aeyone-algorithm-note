#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

double log3(int x) {
    return log(x) / log(3);
}

void solve() {
	int x;
	cin >> x;
	i64 ans = 0;
	while(x > 0){
		int cnt = log3(x) + 0.00000000001;
		x -= (int)pow(3, cnt);
		ans += (pow(3, cnt + 1) + (i64)cnt * pow(3, cnt - 1));
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