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
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), s[0]) == n) {
		cout << 1 << '\n';
		return;
	}
	s = s + s;
	int l = 0, r = n - 1;
	while (r < 2 * n && s[l] == s[r]) {
		l ++, r ++;
	}
	string str = s.substr(l, n);
	int ans = 0;
	bool ok = false;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && str[l] == str[r]) {
			r ++;
		}
		ans ++;
		ok |= (r - l >= 2);
	}
	cout << ans + ok << '\n';
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