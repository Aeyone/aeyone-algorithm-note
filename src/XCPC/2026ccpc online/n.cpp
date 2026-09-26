#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	if (s[1] >= '4' || m >= 50 || 5 * m >= n) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}