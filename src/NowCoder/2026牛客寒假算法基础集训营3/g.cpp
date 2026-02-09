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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	i64 sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		sum1 += a[i];
	}
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
		sum2 += b[i];
	}
	int cnt = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (sum1 >= sum2) {
		while (sum1 >= sum2) {
			sum1 -= a.back();
			a.pop_back();
			cnt ++;
		}
	} else {
		while (sum1 < sum2) {
			sum2 -= b.back();
			b.pop_back();
			cnt ++;
		}
	}
	cout << cnt << '\n';
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