#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve1(int idx) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> dis(n, -1);
	queue<int> q;
	dis[0] = 0;
	q.push(0);

	while (q.size()) {
		auto u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (dis[v] != -1) {
				continue;
			}
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	string res(n, 'r');
	for (int i = 0; i < n; i ++) {
		if (dis[i] % 3 == 1) {
			res[i] = 'g';
		} else if (dis[i] % 3 == 2) {
			res[i] = 'b';
		}
	}
	cout << res << '\n';
}

void solve2(int idx) {
	int q;
	cin >> q;
	while (q --) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<char, int> mp;
		for (int i = 0; i < n; i ++) {
			if (!mp[s[i]]) {
				mp[s[i]] = i + 1;
			}
		}
		if (mp.size() == 1) {
			cout << mp[s[0]] << '\n';
		}
		if (mp['r'] && mp['b']) {
			cout << mp['r'] << '\n';
		}
		if (mp['r'] && mp['g']) {
			cout << mp['g'] << '\n';
		}
		if (mp['b'] && mp['g']) {
			cout << mp['b'] << '\n';
		}

	}
}


signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	string s;
	cin >> s;
	if (s == "first") {
		int t = 1;
		cin >> t;
		for (int i = 0; i < t; i ++) {
			solve1(i);
		}
	} else {
		int t = 1;
		cin >> t;
		for (int i = 0; i < t; i ++) {
			solve2(i);
		}
	}
	
}