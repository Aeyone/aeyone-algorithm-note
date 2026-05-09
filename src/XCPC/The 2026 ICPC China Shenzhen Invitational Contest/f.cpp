#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector f(n + 1, vector<int>(n + 1, -1));

	auto sg = [&](this auto &&self1, int u, int fa)-> int { // 计算fa -> u的sg函数
		if (f[fa][u] != -1) {
			return f[fa][u];
		}

		set<int> tot;
		auto dfs = [&](this auto &&self2, int u, int fa, int XOR, int dep)-> void { // 递归找所有路径 对于一个确定的路径 则该路径的sg值为所有子树的xor和
			if (dep == k) {
				return;
			}
			for (auto v : g[u]) if (v != fa) {
				XOR ^= self1(v, u);
			}
			tot.insert(XOR);
			for (auto v : g[u]) if (v != fa) {
				self2(v, u, XOR ^ self1(v, u), dep + 1);
			}
		};
		dfs(u, fa, 0, 0);

		int mex = 0;
		for (auto e : tot) {
			if (e != mex) {
				break;
			}
			mex ++;
		}
		f[fa][u] = mex;

		return f[fa][u];
	};

	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i ++) {
		int cur_sg = 0;
		for (auto v : g[i]) {
			cur_sg ^= sg(v, i);
		}
		ans[i] = cur_sg != 0;
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i];
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}