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
    vector<int> a(n), w(n), b(n);
    int W = 0, B = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        W += (a[i] == 1);
        B += (a[i] == 0);
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
    auto dfs = [&](auto &&self, int u, int fa)->void{
        res[u] = (a[u] == 1 ? 1 : -1);
        w[u] = (a[u] == 1);
        b[u] = (a[u] == 0);
        priority_queue<int> heap;
        for(auto v : g[u]) if(v != fa){
            self(self, v, u);
            heap.push(w[v] - b[v]);
            w[u] += w[v];
            b[u] += b[v];
        }
        heap.push((W - w[u]) - (B - b[u]));
        while(heap.size() && heap.top() > 0){
            res[u] += heap.top();
            heap.pop();
        }
    };
    dfs(dfs, 0, -1);
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
