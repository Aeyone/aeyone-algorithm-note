#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

string lltos(i64 num, int base){
    if(num == 0){
        return "0";
    }
    string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while(num){
        res += idx[num % base];
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k, n);
    if(!(k & 1)) {
        a[0] = 0;
        int u = __lg(n) - 1;
        while(u > 0 && !(n >> u & 1)) {
            u --;
        }
        if(u > 0) {
            a[0] ^= (1 << u);
            a[0] ^= n % (1 << u) ^ ((1 << u) - 1);
            a[1] ^= (1 << u);
            a[1] |= ((1 << u) - 1);
        }
    }
    i64 sum = 0;
    int XOR = 0;
    for(auto e : a) {
        XOR ^= e;
        sum += e;
    }
    cout << sum << '\n';
    // for(auto e : a) {
    //  cout << lltos(e, 2) << '\n';
    // }
    // cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}