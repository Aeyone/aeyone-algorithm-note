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
	int x;
	cin >> x;
	int ans = 0, cur = 50;
	while (ans * cur < x) {
		ans ++, cur --;
	}
	string s = string(50, 'A');
	for (int i = 49; ans + i - 49 > 1; i --) {
		s[i] = 'C';		
	}
	if (ans) {
		int idx = x - cur * (ans - 1);
		s[idx] = 'C';
	}
	while (s.back() == 'A' && s.size() > 1) s.pop_back();
	for (auto e : s) cout << e << 'R';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}