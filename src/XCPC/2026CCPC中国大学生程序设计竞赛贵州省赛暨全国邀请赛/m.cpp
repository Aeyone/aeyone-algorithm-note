#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct Hash {
    const u64 P = 131;
    int n;
    vector<u64> h, p; // h[i]存储字符串前i个字母的哈希值, p[i]存储 P^i mod 2^64
    string s;

    Hash () {};
    Hash (int n, string &s) {
        init(n, s);
    }

    void init (int n, string &s) {
        this->n = n, this->s = s;
        h.assign(n + 1, 0);
        p.assign(n + 1, 0);
        p[0] = 1;
        for (int i = 1; i <= n; i ++) {
            h[i] = h[i - 1] * P + s[i];
            p[i] = p[i - 1] * P;
        }
    }
    
    // 计算子串 str[l ~ r] 的哈希值
    u64 get (int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    // 求分别以a,b为起点，长度为len的两个子串的最长公共前缀
    int lcp (int a, int b, int len) {
        int l = 0, r = len, res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get(a, a + mid - 1) == get(b, b + mid - 1)) {
                res = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }

    bool cmp (int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        int min = std::min(len1, len2);

        int k = lcp(l1, l2, min);

        if (k == min) return len1 < len2;
        else return s[l1 + k] < s[l2 + k];
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    s = " " + s;
    Hash hash(n, s);

    vector<pair<int, int>> st;

    for (int i = 1; i <= n; i ++) {
        st.push_back({i, i});

        while (st.size() >= 2) {
            auto [l2, r2] = st.back();
            st.pop_back();

            auto [l1, r1] = st.back();
            st.pop_back();

            if (hash.cmp(l1, r1, l2, r2)) {
                st.push_back({l1, r2});
            } else {
                st.push_back({l1, r1});
                st.push_back({l2, r2});
                break;
            }
        }
    }
    while (st.size() > 1) st.pop_back();

    cout << s.substr(st.back().first, st.back().second) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}