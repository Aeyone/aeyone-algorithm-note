#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

map<string, int> vis, dis;

void init() {
	string st = "123456789";
	vis[st] = 1;
	dis[st] = 0;
	queue<string> q;
	q.push(st);

	while (q.size()) {
		auto s = q.front();
		q.pop();

		for (int i = 0; i < 9; i += 3) {
			string to = s;
			swap(to[i + 2], to[i + 1]);
			swap(to[i + 1], to[i]);
			if (!vis[to]) {
				q.push(to);
				dis[to] = dis[s] + 1;
				vis[to] = 1;
			}
		}

		for (int i = 0; i < 3; i ++) {
			string to = s;
			swap(to[i + 6], to[i + 3]);
			swap(to[i + 3], to[i]);
			if (!vis[to]) {
				q.push(to);
				dis[to] = dis[s] + 1;
				vis[to] = 1;
			}
		}

		string to = s;
		to[2] = s[0];
		to[8] = s[2];
		to[6] = s[8];
		to[0] = s[6];
		to[5] = s[1];
		to[7] = s[5];
		to[3] = s[7];
		to[1] = s[3];
		if (!vis[to]) {
			q.push(to);
			dis[to] = dis[s] + 1;
			vis[to] = 1;
		}
	}
}

void solve() {
	string st, ed;
	for (int i = 0; i < 3; i ++) {
		string s;
		cin >> s;
		st += s;
	}
	for (int i = 0; i < 3; i ++) {
		string s;
		cin >> s;
		ed += s;
	}
	map<char, char> mp;
	for (int i = 0; i < 9; i ++) {
		mp[st[i]] = char('1' + i);
		st[i] = char('1' + i);
	}
	for (auto &e : ed) {
		e = mp[e];
	}
	if (dis.find(ed) == dis.end()) {
		cout << -1 << '\n';
	} else {
		cout << dis[ed] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init();
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}