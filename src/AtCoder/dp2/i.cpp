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
	string s;
	cin >> s;
	map<string, int> mp;
	auto dfs = [&](this auto &&self, string s)->int {
		// cerr << "s = " << s << '\n';
		if (s == "iwi") {
			return 1;
		}
		if (mp.find(s) != mp.end()) {
			return mp[s];
		}
		int res = 0;
		for (int i = 0; i + 2 < s.size(); i ++) {
			if (s.substr(i, 3) == "iwi") {
				res = max(res, 1 + self(s.substr(0, i) + s.substr(i + 3, s.size() - i - 3)));
			}
		}
		return res;
	};
	cout << dfs(s) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}