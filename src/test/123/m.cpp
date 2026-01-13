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
	int ans = 1;
	for (int i = 0; i < n; i ++) {
		int l, r;
		cin >> l >> r;
		ans *= (r - l + 1);
	}
	if (ans <= 1e5) {
		cout << "NO TLE" << '\n';
	} else if (ans <= 1e7){
		cout << "POSSIBLE" << '\n';
	} else {
		cout << "TLE" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}