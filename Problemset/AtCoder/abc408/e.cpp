#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N  = 1e6 + 10;
typedef pair<int, int> PII;

int h[N], e[N], w[N], ne[N], idx;
int dist[N], n, m;
bool vis[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> q;//优先队列存放的是已经确定的最短路
    q.push({0, 1});
    //将第一个元素初始化为距离 使得小根堆根据距离进行排序(默认按照pair的第一个元素排序)

    while(q.size()){

        auto t = q.top();//从已经确定长度的路里面选一条最短的路
        q.pop();

        int idx = t.second;
        int distance = t.first;

        if(vis[idx])//如果该点已经是最短路径了 则进行下一轮循环
            continue;

        vis[idx] = true; //将该点标记为最短路

        for(int i = h[idx]; i != -1; i = ne[i]){//遍历该点所有的边
            int j = e[i];
            if(dist[j] > (dist[idx] | w[i])){//松弛操作, 松弛之后加入优先队列
                dist[j] = (dist[idx] | w[i]);//是w[i] 不能写成w[j] j是目标顶点 而i是边的索引
                q.push({dist[j], j});//每次将元素加入优先队列后会自动在小根堆中进行排序操作
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        return -1;

    return dist[n];
}

void solve() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	cout << dijkstra() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}