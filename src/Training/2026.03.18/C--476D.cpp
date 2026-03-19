#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<array<int, 4>> a(n);
	int mx = 0;
	for (int i = 0; i < n; i ++) {
		mx = max(mx, a[i][0]);
		a[i][0] = i * 6 + 2;
		for (int j = 1; j < 4; j ++) {
			a[i][j] = i * 6 + j * 2 - 1;
			mx = max(mx, a[i][j]);
		}
	}
	cout << mx * k << '\n';
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 4; j ++) {
			cout << a[i][j] * k << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}