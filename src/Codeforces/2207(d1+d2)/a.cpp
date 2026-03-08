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
	bool ok = false;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && s[l] == s[r]) {
			r ++;
		}
		ok |= (s[l] == '1');
		if (ok && s[l] == '0' && r != n && r - l == 1) {
			s[l] = '1';
		}
	}
	int mx = count(s.begin(), s.end(), '1'), mn = 0;
	for (int l = 0, r = 0; l < n; l = r) {
		while (r < n && s[l] == s[r]) {
			r ++;
		}
		if (s[l] == '1') {
			mn += (r - l) / 2 + 1;
		}
	}
	cout << mn << ' ' << mx << '\n';
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