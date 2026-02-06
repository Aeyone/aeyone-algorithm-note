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
	vector g(n, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			g[i][j] = (i & 1);
			g[j][i] = (i & 1);
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << g[i][j] << ' ';
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