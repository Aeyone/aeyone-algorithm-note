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
    i64 n;
    cin >> n;
    vector<i64> a (n);
    i64 sum = 0;
    for (auto& e : a) {
        cin >> e;
        sum += e;
    }
    vector<i64> bit (31);
    for (i64 i = 30; i >= 0; i--) {
        i64 cur = (1ll << i);
        if (sum - (cur - 1) * n > 0) {
            bit[i] = 1;
            if (sum >= cur * n) {
                sum -= cur * n;
            } else {
                sum %= cur;
            }
        }
    }
 
    if (sum > 0) {
        for (i64 i = 0; i <= 30; i++) {
            if (bit[i]) {
                continue;
            }
            if ((1ll << i) * n >= sum) {
                bit[i] = 1;
                break;
            }
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i <= 30; i++) {
        ans += (1ll << i) * bit[i];
    }
    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}