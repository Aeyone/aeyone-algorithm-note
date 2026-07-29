#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;


void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    string t = "Rounddo";
    while (k --) {
        t += 'g';
    }

    auto kmp = [&](string s, string p)-> vector<int> {
        int n = p.size(), m = s.size();
        s = " " + s;  //原始串
        p = " " + p;  //模式串
        vector<int> ne(n + 1), res;
        for (int i = 2, j = 0; i <= n; i ++) { // j此时的意义：i-1位置的前缀函数中，匹配真前缀的最后一个字符的位置
            while (j && p[i] != p[j + 1]) {     // 1~j的位置已经匹配，只需要看i和j+1位置上是否相等
                j = ne[j];                       // 不相等，就往前跳
            }
            if (p[i] == p[j + 1]) {             // 如果相等，说明匹配上了，更新j的位置
                j ++;
            }
            ne[i] = j;
        }
        for (int i = 1, j = 0; i <= m; i ++) {
            while (j && s[i] != p[j + 1]) {
                j = ne[j];
            }
            if (s[i] == p[j + 1]) {
                j ++ ;
            }
            if (j == n) {
                res.push_back(i - n + 1);
                j = ne[j];
            }
        }
        return res;
    };

    
    int n = s.size(), m = t.size();
    s = s + s;

    vector<int> tot = kmp(s, t);
    vector<pair<int, int>> v;
    for (auto u : tot) {
        int l = max(1, u + m - n), r = min(u, n);
        if (l <= r) v.push_back({l, r});
    }
    sort(v.begin(), v.end());
    
    int siz = v.size(), ans = 0;
    for (int l = 0, r = 0; l < siz; l = r) {
        int R = v[l].second;
        while (r < siz && v[r].first <= R) {
            R = v[r].second;
            r ++;
        }
        ans += (R - v[l].first + 1);
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