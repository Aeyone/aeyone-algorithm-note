#include <bits/stdc++.h>

using namespace std;

// 强连通分量类
struct SCC {
    int n;                     // 图的节点数
    vector<vector<int>> adj;   // 邻接表表示的图
    vector<int> stk;           // 存储DFS路径的栈
    vector<int> dfn, low, bel, siz; // dfn：节点的访问时间，low：节点的最小可达时间，bel：每个节点所属强连通分量的编号
    int cur, cnt;              // cur：当前时间戳，cnt：强连通分量的数量

    // 默认构造函数
    SCC() {}

    // 带参数的构造函数，初始化图的节点数
    SCC(int n) {
        init(n);
    }

    // 初始化函数
    void init(int n) {
        this->n = n;       // 设置节点数
        adj.assign(n, {}); // 初始化邻接表
        dfn.assign(n, -1); // 初始化访问时间为-1，表示未访问
        low.resize(n);     // 初始化low数组
        bel.assign(n, -1); // 初始化bel数组，表示每个节点的强连通分量编号
        stk.clear();       // 清空栈
        cur = cnt = 0;     // 当前时间戳和强连通分量计数器初始化为0
    }

    // 添加边的函数
    void addEdge(int u, int v) {
        adj[u].push_back(v); // 在邻接表中添加边 u -> v
    }

    // 深度优先搜索函数
    void dfs(int x) {
        dfn[x] = low[x] = cur++; // 记录访问时间和low值
        stk.push_back(x);        // 将当前节点压入栈中

        // 遍历当前节点的所有邻接节点
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                // 如果邻接节点y未被访问
                dfs(y);                       // 递归访问邻接节点y
                low[x] = min(low[x], low[y]); // 更新当前节点x的low值
            } else if (bel[y] == -1) {
                // 如果邻接节点y已被访问，但不在当前强连通分量中
                low[x] = min(low[x], dfn[y]); // 更新low值
            }
        }

        // 如果当前节点x是一个强连通分量的根节点
        if (dfn[x] == low[x]) {
            int y; // 用于存储从栈中弹出的节点
            do {
                y = stk.back(); // 获取栈顶元素
                bel[y] = cnt;   // 将该节点标记为当前强连通分量
                stk.pop_back(); // 从栈中弹出该节点
            } while (y != x); // 直到弹出当前节点x
            cnt++; // 增加强连通分量的计数
        }
    }

    // 主函数，执行SCC算法
    vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                // 如果节点i未被访问
                dfs(i); // 进行深度优先搜索
            }
        }
        return bel; // 返回每个节点的强连通分量编号
    }
};

void solve() {
	int n, m;      // n：节点数，m：边数
    cin >> n >> m; // 输入节点和边的数量
    SCC scc(n);    // 创建SCC对象
    for (int i = 0; i < m; i ++) {
        int u, v;          // 边的两个端点
        cin >> u >> v;     // 输入边
        u--, v--;
        scc.addEdge(u, v); // 添加边到SCC对象中
    }
    vector<int> result = scc.work(); 

    vector<set<int>> c(n + 1);
    for (int i = 0; i < n; i ++) {
        c[result[i]].insert(i);
    }
    vector<int> col(n), ans(n);
    for (auto st : c) {
    	auto dfs = [&](auto &&self, int u, int fa)->void{
    		for (auto v : scc.adj[u]) {
    			if (v == fa || st.find(v) == st.end()) {
    				continue;
    			}
    			if (!col[v]) {
	    			col[v] = 3 - col[u];
	    			self(self, v, u);
    			}
    		}
    	};
    	int u = *st.begin();
    	col[u] = 1;
    	dfs(dfs, u, -1);
    	bool ok = false;
    	for (auto u : st) {
    		for (auto v : scc.adj[u]) {
    			if (st.find(v) == st.end()) {
    				continue;
    			}
    			ok |= (col[u] == col[v]);
    		}
    	}
    	if (ok) {
    		for (auto e : st) {
    			ans[e] = 1;
    		}
    	}
    }
    for (auto e : ans) {
    	cout << e;
    }
    cout << '\n';
}


// 使用示例
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}