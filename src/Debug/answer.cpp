#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define randll(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

string lltos(i64 num, int base, int siz){
    if(num == 0){
        return string(siz, '0');
    }
    string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res;
    while(num){
        res += idx[num % base];
        num /= base;
    }
    while(res.size() < siz) {
        res += "0";
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    // n = randll(1, 63);
    // k = 4;
    // cout << "n = " << n << '\n';
    std::vector<int> ans(k);
    int s = 0;
    for (int d = 29; d >= 0; d--) {
        int nd = n >> d & 1;
        int c = nd ? k : s;
        if (c % 2 != nd) {
            c--;
        }
        if (nd) {
            s = std::min(k, s + k - c);
        }
        for (int i = 0; i < k; i++) {
            if (c > 0 && (ans[i] >> (d + 1)) < (n >> (d + 1)) && ans[i] + (1 << d) <= n) {
                c--;
                ans[i] += (1 << d);
            }
        }
        for (int i = 0; i < k; i++) {
            if (c > 0 && !(ans[i] >> d & 1) && ans[i] + (1 << d) <= n) {
                c--;
                ans[i] += (1 << d);
            }
        }
        assert(c == 0);
    }
    i64 sum = 0;
    for (int i = 0; i < k; i++) {
        sum += ans[i];
        // std::cout << ans[i] << " \n"[i == k - 1];
    }
    cout << sum << '\n';
    // for(auto e : ans) {
    //  cout << lltos(e, 2, __lg(n) + 1) << '\n';
    // }
    // cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
