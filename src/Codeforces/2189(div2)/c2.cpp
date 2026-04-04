#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve(int n){
	// int n;
	// cin >> n;
	vector<int> a(n + 1);
	ranges::iota(a, 0);
	bool flag = false;
	bool ok = true;
	do {
		ok = true;
		for (int i = 1; i <= n - 1; i ++) {
			bool check = false;
			for (int j = i; j <= n; j ++) {
				check |= (a[i] == (i ^ a[j]));
			}
			ok &= check;
		}
		if (ok) {
			break;
		}
	} while(next_permutation(a.begin() + 1, a.end()));
	if (ok) {
		cerr << "n = " << n << '\n';
		for (int i = 1; i <= n; i ++) {
			cerr << a[i] << ' ';
		}
		cerr << '\n';
		for (int i = 1; i <= n; i ++) {
			cerr << (a[i] ^ i) << ' ';
		}
		cerr << '\n';
	} else {
		cerr << -1 << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	// int _ = 1;
	// cin >> _;
	// while (_ --) {
		// solve();
	// }
	for (int i = 3; i <= 12; i ++) {
		solve(i);
	}
}