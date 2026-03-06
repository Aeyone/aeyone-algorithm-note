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
	int c0 = count(s.begin(), s.end(), '0');
	if (c0 == n) {
		cout << 0 << '\n';
		return;
	}
	int c1 = count(s.begin(), s.end(), '1');
	if (!(c0 & 1) && (c1 & 1)) {
		cout << -1 << '\n';
		return;
	} else if (c0 & 1) {
		cout << c0 << '\n';
		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} else {
		cout << c1 << '\n';
		for (int i = 0; i < n; i ++) {
			if (s[i] == '1') {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
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