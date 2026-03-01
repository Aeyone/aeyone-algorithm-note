#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	int x0, y0, x1, y1, x2, y2;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

	array<int, 3> ans = {INF, 0, 0};
	int sth = 60 * x0 + y0;

	for (int h = x1; h <= x2; h ++) {
		for (int m = (h == x1 ? y1 : 0); (h == x2 ? m <= y2 : m < 60); m ++) {
			int curh = 60 * h + m;
			int needh = abs(sth - curh);
			int needm = abs(m * 12 - y0 * 12);
			cmin(ans, {min(needh, 720 - needh) + min(needm, 720 - needm), h, m});
		}
	}
	cout << ans[1] << ' ' << ans[2] << '\n';
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