#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
	很有意思的计数题
	首先对每个节点u开一个map，记录u的父亲节点的数字出现的次数
	然后因为答案是从小的值递推到大的值
	因此我们按照每个节点的权值，从小到大枚举
	对于每个u，遍历它的每一个子节点v：
		1)因为需要满足a[v]=a[u]+a[fa]，那么显然答案就需要加上mp[u][a[v] - a[u]]，
		2)其实mp[u][num]的含义为: 对于节点u，所有从值为num指向u的路径的条数。
		  那么不仅需要将答案累加上mp[u][a[v] - a[u]]，还需要将mp[v][a[u]]加上mp[u][a[v] - a[u]]
		  意思是，从值为a[v]-a[u]走到u的路径数，应该需要累加到从值为a[u]走到v的路径条数上 
		  因为对于满足条件的v的子节点vv来说，a[v]-a[u] -> a[u] -> a[v] -> a[vv]和a[u] -> a[v] -> a[vv]这两种路径都需要计算
	然后还需要注意一下排序之后的节点的下标映射关系，就做完了~
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<i64, int>> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> id(n);
	for(int i = 0; i < n; i ++) {
		id[a[i].second] = i;
	}
	vector<vector<int>> g(n);
	vector<map<i64, i64>> mp(n);
	for(int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		u = id[u], v = id[v];
		g[u].push_back(v);
		mp[v][a[u].first] ++;
	}
	i64 ans = m;
	for(int i = 0; i < n; i ++) {
		auto [e, u] = a[i];
		for(auto v : g[i]) {
			i64 dif = a[v].first - e;
			if(mp[i].find(dif) != mp[i].end()){
				i64 cnt = mp[i][dif];
				mp[v][e] = (mp[v][e] + cnt) % MOD;
				ans = (ans + cnt) % MOD;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}