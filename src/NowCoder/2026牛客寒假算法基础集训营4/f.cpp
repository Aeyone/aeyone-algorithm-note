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
	int a, b;
	cin >> a >> b;
	if (b >= a) {
		int cnt = b / (2 * a);
		int r = b % (2 * a);
		for (int i = 1; i <= a; i ++) {
			cout << string(cnt + (r > 0), '1');
			r --;
			cout << "0";
			cout << string(cnt + (r > 0), '1');
			r --;
		}
	} else {
		int cnt = a / (2 * b);
		int r = a % (2 * b);
		for (int i = 1; i <= b; i ++) {
			cout << string(cnt + (r > 0), '0');
			r --;
			cout << "1";
			cout << string(cnt + (r > 0), '0');
			r --;
		}
	}
	cout << '\n';
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