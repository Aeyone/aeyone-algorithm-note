#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long
#define pi acos(-1)
#define MOD 1000000007
#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

struct EBCC {
    int n;                   // 图的节点数
    vector<vector<int>> adj; // 邻接表表示的图
    set<pair<int, int>> E;
    vector<int> stk; // 存储DFS路径的栈
    vector<int> dfn, low,
        bel; // dfn：节点的访问时间，low：节点的最小可达时间，bel：每个节点所属边双连通分量的编号
    int cur, cnt; // cur：当前时间戳，cnt：边双连通分量的数量

    // 默认构造函数
    EBCC() {}

    // 带参数的构造函数，初始化图的节点数
    EBCC(int n) { init(n); }

    // 初始化函数
    void init(int n)
    {
        this->n = n;       // 设置节点数
        adj.assign(n, {}); // 初始化邻接表
        dfn.assign(n, -1); // 初始化访问时间为-1，表示未访问
        low.resize(n);     // 初始化low数组
        bel.assign(n, -1); // 初始化bel数组，表示每个节点的边双连通分量编号
        stk.clear();       // 清空栈
        cur = cnt = 0;     // 当前时间戳和边双连通分量计数器初始化为0
    }

    // 添加边的函数
    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // 在邻接表中添加边 u -> v
        adj[v].push_back(u); // 在邻接表中添加边 v -> u（无向图）
    }

    // 深度优先搜索函数
    void dfs(int x, int p)
    {
        dfn[x] = low[x] = cur++; // 记录访问时间和low值
        stk.push_back(x);        // 将当前节点压入栈中

        // 遍历当前节点的所有邻接节点
        for (auto y : adj[x]) {
            if (y == p) { // 如果是父节点，跳过
                continue;
            }
            if (dfn[y] == -1) {               // 如果邻接节点y未被访问
                E.emplace(x, y);              // 将边 (x, y) 加入边集合
                dfs(y, x);                    // 递归访问邻接节点y
                low[x] = min(low[x], low[y]); // 更新当前节点x的low值
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) { // 如果邻接节点y已被访问，但不在当前边双连通分量中
                E.emplace(x, y);              // 将边 (x, y) 加入边集合
                low[x] = min(low[x], dfn[y]); // 更新low值
            }
        }

        // 如果当前节点x是一个边双连通分量的根节点
        if (dfn[x] == low[x]) {
            int y; // 用于存储从栈中弹出的节点
            do {
                y = stk.back(); // 获取栈顶元素
                bel[y] = cnt;   // 将该节点标记为当前边双连通分量
                stk.pop_back(); // 从栈中弹出该节点
            } while (y != x); // 直到弹出当前节点x
            cnt++; // 增加边双连通分量的计数
        }
    }

    // 主函数，执行EBCC算法
    vector<int> work()
    {
        dfs(0, -1); // 从节点0开始DFS，父节点为-1
        return bel; // 返回每个节点的边双连通分量编号
    }

    // 压缩边双连通分量，构建新的图
    struct Graph {
        int n;                        // 新图的节点数
        vector<pair<int, int>> edges; // 新图的边
        vector<int> siz;              // 每个边双连通分量的大小
        vector<int> cnte;             // 记录边双连通分量的边数
    };

    Graph compress()
    {
        Graph g;            // 创建新图对象
        g.n = cnt;          // 新图的节点数为边双连通分量的数量
        g.siz.resize(cnt);  // 初始化边双连通分量大小数组
        g.cnte.resize(cnt); // 初始化边双连通分量边数数组

        // 填充新图信息
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++; // 统计每个边双连通分量的大小
            for (auto j : adj[i]) {
                // 如果边 (i, j) 跨越两个不同的边双连通分量
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]); // 添加边到新图
                } else if (i < j) {                       // 只统计一次边
                    g.cnte[bel[i]]++; // 增加边双连通分量的边数
                }
            }
        }
        return g; // 返回压缩后的新图
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    EBCC c(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        c.addEdge(u, v);
    }
    c.work();
    auto G = c.compress();
    int N = c.cnt;
    vector<vector<int>> g(N);
    vector<int> dep(N);
    vector<array<int, 21>> st1(N), st2(N);
    for (auto [u, v] : G.edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        if (G.siz[i] > 1)
            st2[i][0] = 1;
    }
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        if (fa != -1) {
            st1[u][0] = fa;
        }
        for (int i = 1; i < 21; i++) {
            int la = st1[u][i - 1];
            st1[u][i] = st1[la][i - 1];
            st2[u][i] = st2[u][i - 1] + st2[la][i - 1];
        }
        for (auto v : g[u]) {
            if (v == fa)
                continue;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);
    auto lca = [&](int u, int v) -> int {
        if (dep[v] > dep[u])
            swap(u, v);

        for (int i = 20; i >= 0; i--) {
            int la = st1[u][i];
            if (dep[la] >= dep[v]) {
                u = la;
            }
        }
        if(u == v) return u;
        for (int i = 20; i >= 0; i--) {
            int la1 = st1[u][i], la2 = st1[v][i];
            if (la1 != la2) {
                u = la1, v = la2;
            }
        }
        return st1[u][0];
    };
    // for (int i = 0; i < N; i++) {
    //     cout << "i = " << i << "|";
    //     for (auto v : g[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        s = c.bel[s], t = c.bel[t];
        if (s == t) {
            cout << 0 << endl;
            continue;
        }
        int x = lca(s, t), cur = s;
        int sum = dep[s] + dep[t] - 2 * dep[x] - 1;
        // cout << s << " " << t << " " << x << endl;
        cout << "sum = " << sum << endl;
        for (int i = 20; i >= 0; i--) {
            int la = st1[cur][i];
            if (dep[la] >= dep[x]) {
                sum -= st2[cur][i];
                cur = la;
            }
        }
        cur = t;
        for (int i = 20; i >= 0; i--) {
            int la = st1[cur][i];
            if (dep[la] > dep[x]) {
                sum -= st2[cur][i];
                cur = la;
            }
        }
        cout << sum + st2[s][0] + st2[t][0] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}