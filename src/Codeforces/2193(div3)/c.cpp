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
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 2), b(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
	}
	for (int i = n; i >= 1; i --) {
		a[i] = max({a[i], a[i + 1], b[i]});
	}
	vector<i64> s(n + 2);
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << ' ';
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