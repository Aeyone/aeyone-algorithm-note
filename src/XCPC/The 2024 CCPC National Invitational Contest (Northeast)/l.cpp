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
	int n = s.size(), cnt = 0;
	s = " " + s;
	i64 ans = 1;
	for (int i = n; i >= 1; i --) {
		cnt += (s[i] == ')');
		if (s[i - 1] == ')' && s[i] == ')') {
			ans = (ans * cnt) % MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}