#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<i64> t(n + 1), a(n + 1), look(n + 1);//1表示右边，-1表示左边
	for(int i = 1; i <= n; i ++){
		cin >> t[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		a[i] *= 2;
	}
	for(int i = 1; i <= n; i ++){
		look[i] = (a[t[i]] > a[i] ? 1 : -1);
	}
	vector<i64> ans(n + 1, -1), pos(n + 1);//pos表示追到后的坐标
	auto dfs = [&](auto &&self, int u)->void{
		if(look[u] == look[t[u]]){
			self(self, t[u]);
			ans[u] += ans[t[u]] + abs(a[t[u]] - a[u]);
		}else{
			ans[u] = abs(a[t[u]] - a[u]) / 2;
		}
	};
	for(int i = 1; i <= n; i ++){
		if(ans[i] != -1){
			continue;
		}
		dfs(dfs, i);
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}