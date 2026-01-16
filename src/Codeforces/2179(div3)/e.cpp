#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	i64 s1 = 0, s2 = 0, sum = 0;
	vector<int> p(n);
	for (int i = 0; i < n; i ++) {
		cin >> p[i];
		sum += p[i];
		if (s[i] == '0') {
			s1 += p[i] / 2 + 1;
		} else {
			s2 += p[i] / 2 + 1;
		}
	}
	bool ok = true;
	ok &= (sum <= x + y);
	ok &= (x >= s1 && y >= s2);
	if (count(s.begin(), s.end(), '1') == n) {
		ok &= (y >= x + n);
	}
	if (count(s.begin(), s.end(), '0') == n) {
		ok &= (x >= y + n);
	}
	if (ok) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}