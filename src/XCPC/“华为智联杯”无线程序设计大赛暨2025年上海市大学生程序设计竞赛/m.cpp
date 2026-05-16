#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve () {
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }
    i64 ans = 0, cur = 0;
    for (int i = 32; i >= 0; i --) {
        int cnt = 0;
        for (int j = 0; j < n; j ++) {
            cnt += (a[j] >> i & 1);
        }
        cur += cnt;
        ans += x * cnt + (i == 0 ? 0 : min((i128)y, (i128)x * cur));
        cur <<= 1;
    }
    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}