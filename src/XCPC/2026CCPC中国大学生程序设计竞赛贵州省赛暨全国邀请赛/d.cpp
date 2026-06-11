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
    i64 n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<i64> s(n + 1);
    for (int i = 0; i < n; i ++) cin >> a[i];

	if (k == 0) {
		int q;
		cin >> q;
		while (q --) {
			i64 x;
			cin >> x;
			cout << x * (2 * n - x + 1) / 2 << '\n';
		}
		return;
	}

    s[0] = a[0];
    for (int i = 1; i < n; i ++) s[i] = s[i - 1] + a[i];

    const int pow = 21;
    vector<array<i64, pow>> st(n);
    for (int i = 0; i < n; i ++) st[i][0] = s[i];

    for (int p = 1; n >> p > 0; p ++) {
        for (int i = 0; i + (1 << p) <= n; i ++) {
			st[i][p] = std::max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
        }
    }

	auto query = [&](int l, int r)-> i64 {
		int d = __lg(r - l + 1);
		return std::max(st[l][d], st[r - (1 << d) + 1][d]);
	};

	vector<i64> ans(n + 2);
	vector<int> res(n + 1, INF);
	
	for (int i = 0; i < n; i ++) {
		int l = i, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(i, mid) >= k + (i > 0 ? s[i - 1] : 0)) {
				res[i] = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}

	for (int i = n - 1; i >= 0; i --) res[i] = std::min(res[i], res[i + 1]);

	for (int i = 0; i < n; i ++) {
		if (res[i] == INF) continue;
		int len = res[i] - i + 1;
		ans[len] ++;
		ans[len + n - res[i]] --;
	}

	for (int i = 1; i <= n; i ++) ans[i] += ans[i - 1];
	for (int i = 1; i <= n; i ++) ans[i] += ans[i - 1];

    int q;
    cin >> q;
    while (q --) {
        int x;
        cin >> x;
		if (k == 0) {
			cout <<  (i64)x * (2 * n - x + 1) / 2 << '\n';
		} else {
			cout << ans[x] << '\n';
		}
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;
    while (t --) {
        solve();
    }
}
