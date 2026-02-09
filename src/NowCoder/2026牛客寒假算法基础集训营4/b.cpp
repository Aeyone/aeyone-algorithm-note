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
	int n, q, s;
	cin >> n >> q >> s;
	vector<int> t(n + 1), pre(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + t[i];
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		cout << s + pre[x - 1] + y - 1 << '\n';
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