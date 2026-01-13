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
	vector<array<int, 2>> a(n);
	int x, y;
	for (int i = 0; i < n; i ++) {
		cin >> a[i][0] >> a[i][1];
		if (!i) {
			x = a[i][0], y = a[i][1];
		}
	}
	sort(a.begin(), a.end(), [](const array<int, 2> &p, const array<int, 2> &q)->bool{
		return (p[0] > q[0] || (p[0] == q[0] && p[1] <= q[1]));
	});
	for (int i = 0; i < n; i ++) {
		auto [p, q] = a[i];
		if (p == x && q == y) {
			if (n / 10 > i) {
				cout << "gold" << '\n';
			} else if (n / 10 * 3 > i) {
				cout << "silver" << '\n';
			} else if (n / 10 * 6 > i) {
				cout << "bronze" << '\n';
			} else {
				cout << "iron" << '\n';
			}
		}
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