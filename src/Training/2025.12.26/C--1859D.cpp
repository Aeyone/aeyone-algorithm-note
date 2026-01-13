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
	vector<array<int, 4>> seg(n);
	for (int i = 0; i < n; i ++) {
		cin >> seg[i][0] >> seg[i][1] >> seg[i][2] >> seg[i][3];
	}
	sort(seg.begin(), seg.end());
	vector<int> to(n);
	for (int l = 0, r = 0, ed = seg[0][3]; l < n; l = r) {
		while (r < n && seg[r][0] <= ed) {
			ed = max(ed, seg[r ++][3]);
		}
		for (int i = l; i < r; i ++) {
			to[i] = ed;
		}
		if (r < n) {
			ed = seg[r][3];
		}
	}
	int q;
	cin >> q;
	while (q --) {
		int x;
		cin >> x;
		int idx = lower_bound(seg.begin(), seg.end(), array<int, 4>{x, INF, INF, INF}) - seg.begin() - 1;
		cout << max(x, (idx >= 0 ? to[idx] : 0)) << ' ';
	}
	cout << '\n';
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