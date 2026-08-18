#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int N = 1e6 + 10;
int son[N][26], cnt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int idx = 0;
	vector<string> a(n);
	vector<vector<int>> id(n);
	vector<queue<int>> t(N);
	vector<int> dep(N);

	auto insert = [&](string s, int T)-> void {
		int p = 0;
		for(int i = 0; i < s.size(); i ++) {
			int u = s[i] - 'a';
			if(!son[p][u]) son[p][u] = ++ idx;
			dep[son[p][u]] = dep[p] + 1;
			p = son[p][u];

			id[T][i] = p;
			t[p].push(T);
		}
	};

	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		id[i].assign(a[i].size(), 0);
		insert(a[i], i);
	}

	for (int i = 1; i <= idx; i ++) {
		t[i].pop();
		t[i].push(INF);
	}

	set<array<int, 3>> st;
	vector<int> vis(idx + 1, -1);

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < a[i].size(); j ++) {
			int u = id[i][j];
			if (vis[u] != -1) {
				st.erase({vis[u], dep[u], u});
			} else {
				ans ++;
			}
			st.insert({t[u].front(), dep[u], u});
			vis[u] = t[u].front();
			t[u].pop();
		}
		while (st.size() > m) {
			auto it = (--st.end());
			auto [_, __, u] = *it;
			st.erase(it);
			vis[u] = -1;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}