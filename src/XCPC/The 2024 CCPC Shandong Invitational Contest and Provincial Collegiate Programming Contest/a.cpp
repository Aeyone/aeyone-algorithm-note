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
	if (n == 0) return os << '0';
    string s;
    while(n) {
    	s += '0' + n % 10;
    	n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}


void solve() {
	i64 n, k;
	cin >> n >> k;
	i128 _k = k;
	vector<array<i128, 3>> a(n);
	for (int i = 0; i < n; i ++) {
		i64 x, y, z;
		cin >> x >> y >> z;
		a[i] = {x, y, z};
	}
	auto check = [&](i128 m)->bool {
		i128 sum = 0;
		for (auto [t, l, w] : a) {
			i128 T = t * l + w;
			i128 cnt = m / T, r = m % T;
			sum += cnt * l + min(l, r / t);
		}
		return (sum >= _k);
	};

	i128 l = 0, r = (i128)INFLL * INFLL, ans = -1;
	while (l <= r) {
		i128 mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
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