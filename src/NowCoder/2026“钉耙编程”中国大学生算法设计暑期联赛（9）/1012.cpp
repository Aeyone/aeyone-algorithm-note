#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long
#define pi acos(-1)
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    void modify(int x, const T &v) { // 单点修改
        while(x <= n){
            a[x] += v, x += x & -x;
        }
    }

    void modify(int l, int r, const T &v) { // 区间修改(差分优化)
        modify(l, v), modify(r + 1, -v);
    }
    
    T query(int x) {// 查询1~x的和 or 单点查询(差分优化)
        T ans{};
        while(x > 0){
            ans += a[x], x -= x & -x;
        }
        return ans;
    }
    // 1-based
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void fill () { //初始化为全1
        for (int x = 1; x <= n; x ++) {
            a[x] += x & (-x);
        }
    }

    int select (T k) { // 选择满足前缀和<=k的最大下标，要求所有值非负，且k从1开始
        int x = 0;
        T cur {};
        for (int i = __lg(n); ~i; i --) {
            x += (1 << i);
            if (x > n || cur + a[x] >= k) x -= (1 << i);
            else cur += a[x];
        }
        return x + 1;
    }
};

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> b(2e5 + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        b[a[i - 1] + a[i + 1]].push_back(a[i]);
    }

    Fenwick<int> fw(1e5 + 10);
    for (int i = 2; i <= 2e5; i++) {
        for (auto e : b[i]) {
            ans += fw.query(1, e - 1);
        }
        for (auto e : b[i]) {
            fw.modify(e, 1);
        }
    }
    auto work = [&](int i) -> int {
        if (i == 1)
            return (a[i + 1] - a[i]) * (a[i + 1] - a[i]);
        if (i == n)
            return (a[i - 1] - a[i]) * (a[i - 1] - a[i]);
        return (a[i + 1] - a[i]) * (a[i + 1] - a[i]) + (a[i - 1] - a[i]) * (a[i - 1] - a[i]);
    };
    for (int i = 2; i <= n; i++) {
        int sum1 = work(i) + work(1);
        swap(a[i], a[1]);
        int sum2 = work(i) + work(1);
        swap(a[i], a[1]);
        if (sum1 < sum2)
            ans++;
    }
    for (int i = 2; i < n; i++) {
        int sum1 = work(i) + work(n);
        swap(a[i], a[n]);
        int sum2 = work(i) + work(n);
        swap(a[i], a[n]);
        if (sum1 < sum2)
            ans++;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}