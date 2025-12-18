#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const ll N = 1e7 + 1;

void solve () {
    int n;
    cin >> n;
    vector<int> a(1 << n), mi(n + 1);
    for(int i = 0; i <= n; i ++){
        mi[i] = (int)pow(3, i);
    }
    for(int i = 0; i < (1 << n); i ++){
        cin >> a[i];
    }
    vector<int> s, sum(mi[n]);
    auto dfs = [&](auto &&self, int cnt)->void{
        if(cnt == n){
            int la = -1, idx = 0, idx2 = 0;
            for(int i = 0; i < n; i ++){
                idx += s[i] * mi[i];
                idx2 += s[i] * (1 << i);
                if(la == -1 && s[i] == 2){
                    la = i;
                }
            }
            if(la == -1){
                sum[idx] = a[idx2];
            }else{
                sum[idx] = sum[idx - mi[la]] + sum[idx - 2 * mi[la]];
            }
            return;
        }
        for(int i = 0; i < 3; i ++){
            s.push_back(i);
            self(self, cnt + 1);
            s.pop_back();
        }
    };
    dfs(dfs, 0);
    int ans = 0;
    for(auto e : sum){
        ans ^= e;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}