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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s = "x" + s;
    vector<int> ans(n + 1);
    int idx = n + 1;
    for(int l = 1, r = 1; l <= n; l ++, r = max(r, l)) {
        ans[l] = ans[l - 1];
        if(s[l] == '0') {
            continue;
        }
        while(r <= n && s[r] == s[l]) {
            r ++;
        }
        if(r > n) {
            ans[l] = -1;
        }else{
            ans[l] += (r - l);
            swap(s[l], s[r]);
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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