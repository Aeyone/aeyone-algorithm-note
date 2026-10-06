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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = n - 2, sum = 0;

	for (int i = 1; i < n - 1; i ++) {
		sum += a[i];
		if (cnt >= 5 && a[i] < a[0] * 3) {
			cnt -= 3;
			sum += a[i];
		}
	}
	if (n <= 3) {
		cnt += 2;
	}
	sum += a[0] * cnt;
	cout << sum << '\n';
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