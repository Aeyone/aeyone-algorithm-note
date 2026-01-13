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
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	i64 sum = 0;
	for (int i = 2; i <= n; i ++) {
		sum += abs(a[i] - a[i - 1]);
	}
	i64 res = sum;
	for (int i = 1; i <= n; i ++) {
		int back = (i != n ? abs(a[i + 1] - a[i]) : 0) + (i != 1 ? abs(a[i] - a[i - 1]) : 0);
		int now = (i != n && i != 1 ? abs(a[i + 1] - a[i - 1]) : 0);
		res = min(res, sum - back + now);
	}
	cout << res << '\n';
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