#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
int st[1001][10000][15];

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> arr(n);
    for(auto &[p, a, b] : arr){
        cin >> p >> a >> b;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= 1000; j ++){
            st[j][i][0] = (arr[i][0] >= j ? 500, j + arr[i][1] : max(0, j - arr[i][2]));
        }
    }
    for(int d = 1; n >> d > 0; d ++){
        for(int i = 0; i + (1 << d) <= n; i ++){
            for(int j = 0; j <= 1000; j ++){
                st[j][i][d] = st[st[j][i][d - 1]][i + (1 << (d - 1))][d - 1];
            }
        }
    }
    vector<int> pre(n);
    pre[0] = arr[0][2];
    for(int i = 1; i < n; i ++){
        pre[i] = pre[i - 1] + arr[i][2];
    }
    int q;
    cin >> q;
    while(q --){
        int x;
        cin >> x;
        int u = 0;
        if(x > 500){
            u = lower_bound(pre.begin(), pre.end(), x - 500) - pre.begin();
            if(u == n){
                cout << x - pre[n - 1] << '\n';
                continue;
            }
            x -= pre[u ++];
        }
        int d = n - u;
        while(d > 0){
            int lb = d & -d;
            x = st[x][u][__lg(lb)];
            u += lb, d -= lb;
        }
        cout << x << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    // cin >> _;
    while (_ --) {
        solve();
    }
}