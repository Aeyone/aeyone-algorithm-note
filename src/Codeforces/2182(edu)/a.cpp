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
	int ok1 = false, ok2 = false;
	for (int i = 0; i < n - 3; i ++) {
		ok1 |= (s[i] == '2' && s[i + 1] == '0'&& s[i + 2] == '2' && s[i + 3] == '5');
		ok2 |= (s[i] == '2' && s[i + 1] == '0'&& s[i + 2] == '2' && s[i + 3] == '6');
	}
	if (ok1 && !ok2) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
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