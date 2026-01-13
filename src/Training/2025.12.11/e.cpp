#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const ll N = 1e7 + 1;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve () {
    ll n, s, x, ans = 0;
    cin >> n >> s >> x;
    map<ll, vector<ll>> mp;
    vector<ll> a(n + 1), sum(n + 1);
    vector<vector<ll>> st(n + 1, vector<ll>(20));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        st[i][0] = a[i];
        mp[sum[i]].push_back(i);
    }
    for (int p = 1; n >> p > 0; p ++) { //枚举所有p
        for (int i = 1; i + (1 << p) <= n + 1; i ++) { //从下标 i 开始的长度为 2^p 的区间大小不能超过n
            st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
        }
    }
    auto query = [&](int l, int r)->int{
        int p = __lg(r - l + 1);
        return max(st[l][p], st[r - (1 << p) + 1][p]);//取从l开始的2^p格内和以r结尾的2^p格内的最大值
    };
    for (int i = 1; i <= n; i++) {
        if (a[i] > x)
            continue;
        int l = i, r = n, c1 = -1, c2 = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int z = query(i, mid);
            if (z <= x) {
                c1 = (z == x ? mid : c1);
                l = mid + 1;
            } else
                r = mid - 1;
        }
        l = i, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int z = query(i, mid);
            if (z >= x) {
                c2 = (z == x ? mid : c2);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        if (c1 == -1 || c2 == -1){
            continue;
        }
        if(mp.find(sum[i - 1] + s) == mp.end()){
        	continue;
        }
        auto &b = mp[sum[i - 1] + s];
        auto it1 = lower_bound(b.begin(), b.end(), c2);
        auto it2 = upper_bound(b.begin(), b.end(), c1);
        if (it1 == b.end() || it2 == b.begin())
            continue;
        it2--;
        ans += it2 - it1 + 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}