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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    int ans = 0;
    auto dfs = [&](auto &&self, int i)->void{
        if(i == k) {
            int XOR = 0, sum = 0;
            for(auto e : a) {
                XOR ^= e;
                sum += e;
            }
            if(XOR == n) {
                ans = max(ans, sum);
            }
            return;
        }
        for(int num = 0; num <= n; num ++) {
            a[i] = num;
            self(self, i + 1);
        }
    };
    dfs(dfs, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    cin >> _;
    while (_ --){
        solve();
    }
}