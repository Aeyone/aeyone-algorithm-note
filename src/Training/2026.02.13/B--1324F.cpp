/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int t[2] {};
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        t[0] += (a[i] == 0);
        t[1] += (a[i] == 1);
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> res(n);
    auto dfs1 = [&](auto &&self, int u, int fa)->void{
        res[u] = (a[u] == 1 ? 1 : -1);
        for(auto v : g[u]) if(v != fa){
            self(self, v, u);
            res[u] += max(0, res[v]);
        }
    };
    auto dfs2 = [&](auto &&self, int u, int fa)->void{
        for(auto v : g[u]) if(v != fa){
            res[v] = max(res[v], (res[v] < 0 ? res[v] : 0) + res[u]);
            self(self, v, u);
        }
    };
    dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1);
    for(auto e : res){
        cout << e << ' ';
    }
    cout << '\n';   
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_ --){
        solve();
    }
}