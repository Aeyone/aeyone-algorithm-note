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
	i64 ans = 0;
	auto check = [&](string s)->i64{
		int m = s.size();
		i64 res = 0;
		for (int i = 0; i < m;) {
			if (s[i] == '0') {
				i ++;
			} else {
				ans ++;
				i += 3;
			}
		}
		return res;
	};
	for (int i = 0; i < n; i ++) {
		for (int len = 1; len + i <= n; len ++) {
			ans += check(s.substr(i, len));
		}
	}
	cout << ans << '\n';
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