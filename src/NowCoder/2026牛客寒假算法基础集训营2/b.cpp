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
	vector<int> a(n);
	map<int, int> mp;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		mp[a[i]] ++;
	}
	int mx = (--mp.end())->first;
	string res;
	if (mp.size() != 1) {
		if (mp[mx] & 1) {
			for (auto e : a) {
				cout << (e == mx);
			}
			cout << '\n';
		} else {
			for (auto e : a) {
				cout << (e != mx);
			}
			cout << '\n';
		}
	} else {
		if (mp[mx] & 1) {
			res = string(n, '1');
			cout << res << '\n';
		} else {
			res = string(n, '0');
			cout << res << '\n';
		}
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