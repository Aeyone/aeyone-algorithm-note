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
	i64 n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;

	i64 r = (x + y) % n, xx = x, yy = y;

	vector<int> v1, v2;

	i64 up = (x + y + n - 1) / n, lo = (x + y) / n;
	for (int i = 0; i < n; i ++) {
		i64 cnt;
		if (i < r) {
			cnt = up;
		} else {
			cnt = lo;
		}

		if (s[i] == '0') {
			xx -= cnt;
		}

		if (s[i] == '1') {
			yy -= cnt;
		}

		if (s[i] == '2') {
			if (i < r) v1.push_back(i);
			else v2.push_back(i);
		}
	}

	if (xx < 0 || yy < 0) {
		cout << -1 << '\n';
		return;
	}

	string ans = s;

	if (lo == 0) {
		for (int i = 0; i < v1.size(); i ++) {
			ans[v1[i]] = i < xx ? '0' : '1';
		}
		for (int j = 0; j < v2.size(); j ++) {
			ans[v2[j]] = '0';
		}
		cout << ans << '\n';
		return;
	}

	// cerr << "v2.size() = " << v2.size() << ' ';
	// cerr << "xx = " << xx << ' ';
	// cerr << "yy = " << yy << ' ';
	// cerr << '\n';
	for (int i = v1.size(); i >= 0; i --) {
		if (xx >= i * up && (xx - i * up) % lo == 0) {
			// cerr << "i = " << i << '\n';
			i64 d = (xx - i * up) / lo;
			if (d <= v2.size()) {
				for (int j = 0; j < v1.size(); j ++) {
					ans[v1[j]] = j < i ? '0' : '1';
				}
				for (int j = 0; j < v2.size(); j ++) {
					ans[v2[j]] = j < d ? '0' : '1';
				}
				cout << ans << '\n';
			} else {
				// cerr << "a" << ' ';
				cout << -1 << '\n';
			}
			return;
		}
	}
	// cerr << "b" << ' ';
	cout << -1 << '\n';
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