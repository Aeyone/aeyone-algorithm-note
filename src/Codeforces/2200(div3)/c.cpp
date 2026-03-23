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
	for (int i = 0; i < 2 * n; i ++) {
		string t;
		for (auto e : s) {
			if (e != '*') {
				t += e;
			}
		}
		for (int i = 1; i < t.size(); i ++) {
			if (t[i] == t[i - 1]) {
				t[i] = '*', t[i - 1] = '*';
			}
		}
		s = t;
	}
	if (s.size() == 0) {
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