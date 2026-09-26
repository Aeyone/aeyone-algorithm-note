#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << -1 << '\n';
		return;
	}
	cout << 1 << ' ' << -1 << ' ' << n / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}