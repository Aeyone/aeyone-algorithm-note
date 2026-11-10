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

ostream& operator<<(ostream &os, __int128 n) {
	string s;
	while(n) {
		s += '0' + n % 10;
		n /= 10;
	}
	reverse(s.begin(), s.end());
	if (s.size() == 0) {
		s = "0";
	}
	return os << s;
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> b[i];
	}

	auto check = [&](int mid)-> i128 {
		int pre = 0;
		i128 ans = x * mid;
		for (int i = 0; i < n; i ++) {
			pre -= a[i] - (i ? a[i - 1] : 0);
			pre = max(pre, 0ll);
			int cnt = max(0ll, b[i] - mid - pre);
			ans += cnt * y;
			pre += cnt;
		}
		return ans;
	};

	int l = 0, r = 1e9;
	while (l + 20 <= r) {
		int m1 = l + (r - l) / 3;
		int m2 = l + (r - l) * 2 / 3;
		i128 a1 = check(m1), a2 = check(m2);
		if (a1 < a2) {
			r = m2;
		} else if (a1 > a2) {
			l = m1;
		} else {
			l = m1, r = m2;
		}
	}
	i128 min = INFLL;
	for (int i = l; i <= r; i ++) {
		min = std::min(min, check(i));
	}
	cout << min << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}