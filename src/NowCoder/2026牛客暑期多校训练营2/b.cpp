#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

struct Basis {
    int b[60];
    Basis() { memset(b, 0, sizeof(b)); }
    void insert(int x)
    {
        for (int i = 59; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!b[i]) {
                    b[i] = x;
                    break;
                }
                x ^= b[i];
            }
        }
    }
    int max_xor() const {
        int ans = 0;

        for (int i = 59; i >= 0; --i) {
            ans = max(ans, ans ^ b[i]);
        }

        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int bit[32] {};
    Basis b;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b.insert(a[i]);
        for (int j = 0; a[i] >> j > 0; j ++) {
            bit[j] += (a[i] >> j & 1);
        }
    }
    int x = b.max_xor();
    i64 ans = 0;
    for (int i = 0; i < 30; i ++) {
        if (!bit[i]) continue;
        if (bit[i] & 1) ans += (1ll << i);
        else if (x >> i & 1) ans += (2ll << i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}