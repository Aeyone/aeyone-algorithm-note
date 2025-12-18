#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for(int i = 0; i < n; i ++)
		cin >> l[i] >> r[i];
	vector<vector<int>> g(n);
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	i64 ans = 0;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			l[u] = min(r[u], max(l[u], l[v]));
		}
		for(auto v : g[u]) if(v != fa){
			ans += max(0, l[v] - r[u]);
		}
	};
	dfs(dfs, 0, -1);
	cout << l[0] + ans << '\n';
	/*
	假设0为根节点
	对于每个节点i，l[u]最多加到r[u]，大于r[u]的部分计算至全局贡献ans中
	因为大于r[u]的部分是由子节点的l[v]大于当前r[u]而产生的，因此不能将这一部分计算在更新后的l[u]当中
	这里更新后的l[u]的含义为 使u节点为根的子树的值都相等 且减去全局贡献的u节点的值

	为什么要把全局贡献分开？
	在对一个根为u的子树进行操作时 有两种情况
		1、子节点的最小可能值小于r[u]
		2、子节点的最小可能值大于r[u]
	对于第一种情况 只需要在子树中进行加法操作 不会影响到0号根节点
	对于第二种情况 需要将子节点作为u' 然后将u作为v' 然后进行全局的加法操作
	这个过程只会对u和v的差值造成影响 其他的节点的值之间的差值不应该受影响 因此全局的加法操作不能更新l[u] 不然就会影响到后面的节点
	要么你就把剩下所有节点的值都加上它俩的差值 显然这是不可能实现的 因此把全局贡献存在ans中就行了
	*/
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}