#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int P = 64;

void solve() {
	i64 s, m;
	cin >> s >> m;
	bitset<P> bs(s), bm(m);
	vector<i64> cnt(P);
	for (int i = P - 1; i >= 0; i --) {
		cnt[i] = bs[i];
	}
	for (int i = P - 1; i > 0; i --) {
		if (!bm[i]) {
			cnt[i - 1] += 2ll * cnt[i];
			cnt[i] = 0;
		}
	}
	auto check = [&](i64 x)-> bool {
		vector<i64> cur = cnt;
		for (int i = P - 1; i > 0; i --) {
			if (!bm[i]) {
				cur[i - 1] += 2ll * cur[i];
				cur[i] = 0;
			} else if (cur[i] > x) {
				cur[i - 1] += 2ll * (cur[i] - x);
				cur[i] = x;
			}
		}
		return cur[0] <= (bm[0] ? x : 0);
	};

	i64 l = 0, r = INFLL, ans = -1;

	while (l <= r) {
		i64 mid = (l + r) >> 1;
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