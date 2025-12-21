#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//1693B 比较有趣的一个树上问题，把树分叉的性质与求和结合在一起，比较典。
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int v = 1; v < n; v ++){
		int u;
		cin >> u;
		u --;
		g[u].push_back(v);
	}
	vector<i64> cnt(n), sum(n), l(n), r(n);//sum[u]表示经过u的所有路径的总和
	for(int i = 0; i < n; i ++){
		cin >> l[i] >> r[i];
	}
	auto dfs = [&](auto &&self, int u)->void{
		for(auto v : g[u]){
			self(self, v);
			sum[u] += sum[v];
			cnt[u] += cnt[v];
		}
		if(sum[u] < l[u]){				//贪心的把所有需要添加一条1~u的路径的节点设置为r[u]
			cnt[u] ++, sum[u] = r[u];	//在此基础上如果权值都不够的话就需要加一条1~u的路径
		}
		sum[u] = min(sum[u], r[u]);
	};
	dfs(dfs, 0);
	cout << cnt[0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}